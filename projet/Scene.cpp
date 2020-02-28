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

Scene::Scene() : eye(Vector3(0, 0, 20))
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
				Vector3 pixel(
					((float)x - (float)width/2.f) / (float)width,
					((float)y - (float)height/2.f) / (float)height,
					0
				);
				Ray ray(eye, pixel - eye);
				// cout << ray.GetDirection().norm() << endl;
				Colorf color;
				if (castRay(ray, color))
				{
					// cout << intersection << endl;
					data[idx] = color.GetBlueAsuchar();
					data[idx + 1] = color.GetGreenAsuchar();
					data[idx + 2] = color.GetRedAsuchar();
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

bool Scene::castRay(Ray ray, Colorf& res_color)
{
	Intersection intersection;
	Intersection closestIntersection = Intersection{
		Vector3(1e5, 1e5, 1e5),
		Vector3(),
		Colorf()
	};

	bool hit = false;
	for (auto& obj:objects)
	{
		if (obj->Intersect(ray, intersection))
		{
			hit = true;
			float d1 = (intersection.point - ray.GetStart()).norm();
			float d2 = (closestIntersection.point - ray.GetStart()).norm();
			if (d1 < d2) {
				closestIntersection = intersection;
			}
		}
	}
	if (!hit) return false;
	// get closest intersection
	Vector3 normal, reflection, point;
	Colorf color, matColor;
	for (auto& light : lights)
	{
		normal = closestIntersection.normal;
		Vector3 I = ray.GetDirection().multiply(-1.f);
		reflection = normal.multiply(I.dot(normal)).multiply(2) - I;
		reflection = reflection.normalize();

		point = closestIntersection.point;
		float diffuseIntensity = max( normal.dot(light->GetDirection(point)), 0.0f );
		float reflectionIntensity = max(reflection.dot(light->GetDirection(point)), 0.0f);
		reflectionIntensity = pow(reflectionIntensity, 10.0);
		// cout << reflectionIntensity << endl;
		matColor = closestIntersection.color;
		color = color + matColor * light->GetColor() * diffuseIntensity +
			matColor * light->GetColor() * reflectionIntensity * 0.8;

	}
	color = color * (1. / (float)lights.size());
	res_color = color;
	return true;
}
