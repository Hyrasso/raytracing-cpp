// projet.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Bmpfile.h"
#include "Vector3.h"
#include "Scene.h"
#include "Sphere.h"
#include "IntersectionObject3d.h"
#include "DirectionalLight.h"
#include "PointLight.h"

#include <iostream>
#include "projet.h"

using namespace std;

int main() {

	Scene scene;
	/*
	unique_ptr<IntersectionObject3d> interobj(new IntersectionObject3d());
	unique_ptr<Sphere> sphere(new Sphere(Vector3(0, 0.5, -25), 0.5, Colorf(1.0, 0.0, 0.0)));
	interobj->AddObject(move(sphere));
	interobj->AddObject(make_unique<Sphere>(Vector3(-0.2, 0, -25.5), 0.5, Colorf(1.0, 0.0, 0.0)));
	scene.addObject(move(interobj));
	*/

	
	unique_ptr<Sphere> sphere1(new Sphere(Vector3(0, 0, -20), 0.7, Colorf(1.0, 0.0, 0.0)));
	scene.addObject(move(sphere1));
	unique_ptr<Sphere> sphere2(new Sphere(Vector3(0.4, 0, -20), 0.5, Colorf(.0, 1.0, 1.0)));
	scene.addObject(move(sphere2));
	

	scene.addLight(make_unique<PointLight>(Vector3(5, 2, -20), Colorf(1.0, 1.0, 1.0)));
	scene.addLight(make_unique<DirectionalLight>(Vector3(-1, -1, 0), Colorf(0.5, 1.0, 0.5)));
	scene.RayTrace("raytrace.bmp", 400, 400);
	return 0;
}
