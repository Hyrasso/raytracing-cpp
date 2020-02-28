#pragma once
#include "Sphere.h"
#include "Light.h"
#include <string>
#include <vector>
#include <memory>

class Scene
{
public:
	Scene();
	~Scene();
	void RayTrace(std::string filename, unsigned int width, unsigned int height);
	void addObject(std::unique_ptr<Object3d> obj);
	void addLight(std::unique_ptr<Light> light);
	bool castRay(Ray ray, Colorf& color);

	Vector3 eye;
	std::vector<std::unique_ptr<Object3d>> objects;
	std::vector<std::unique_ptr<Light>> lights;
};
