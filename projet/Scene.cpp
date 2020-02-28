#include "stdafx.h"
#include "Scene.h"
#include "Bmpfile.h"
#include "Vector3.h"
#include "Ray.h"
#include "Sphere.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

Scene::Scene() : objects(std::vector<std::unique_ptr<Object3d>>()), eye(Vector3(0, 0, -20))
{
}


Scene::~Scene()
{
}

void Scene::RayTrace(std::string filename, unsigned int width, unsigned int height)
{
	std::cout << "Starting raytracing" << std::endl;
	// TODO: render scene
	// save to file
	unsigned char *data = new unsigned char[width * height * 3];
	Vector3 intersection;
	for (unsigned int x = 0;x < width;x++)
		for (unsigned int y = 0;y < height;y++) 
		{
			{
				int idx = (x + y * width) * 3;
				Vector3 pixel((float)x - (float)width/2.f, (float)y - (float)height/2.f, 0);
				pixel = pixel.multiply(0.05f);
				Ray ray(eye, pixel - eye);
				// cout << ray.GetDirection().norm() << endl;
				unsigned char b, g, r;
				if (castRay(ray, b, g, r))
				{
					// cout << intersection << endl;
					data[idx] = b;
					data[idx + 1] = g;
					data[idx + 2] = r;
				}
				else {
					data[idx] = 33;
					data[idx + 1] = 33;
					data[idx + 2] = 33;
				}
			}
		}
	BMPFile::SaveBmp(filename, data, width, height);
	delete[] data;
}

void Scene::addObject(std::unique_ptr<Object3d> obj)
{
	objects.push_back(std::move(obj));
}

void Scene::addLight(std::unique_ptr<Light> light)
{
	lights.push_back(std::move(light));
}

bool Scene::castRay(Ray ray, unsigned char& blue, unsigned char& green, unsigned char& red)
{
	Vector3 interPoint;
	Vector3 closestPoint(FLT_MAX, FLT_MAX, FLT_MAX);
	size_t objIndex = 0;
	bool hit = false;
	for (size_t i=0;i < objects.size();i++)
	{
		if (objects[i]->Intersect(ray, interPoint))
		{
			hit = true;
			float d1 = (interPoint - eye).norm();
			float d2 = (closestPoint - eye).norm();
			if (d1 < d2) {
				closestPoint.set(interPoint);
				objIndex = i;
			}
		}
	}
	if (!hit) return false;
	// get closest intersection
	Vector3 normal;
	Colorf color;
	for (auto& light : lights)
	{
		normal = objects[objIndex]->GetNormal(closestPoint);
		float intensity = normal.dot(light->GetDirection(closestPoint));
		intensity = std::max(intensity, 0.f);
		color = color + objects[objIndex]->GetColor(closestPoint) * light->GetColor() * intensity;
	}
	color = color * (1. / (float)lights.size());
	red = color.GetRedAsuchar();
	green = color.GetGreenAsuchar();
	blue = color.GetBlueAsuchar();
	return true;
}
