#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <cmath>
#include <math.h>

#include "ShapeBuilder.h"

using namespace std;


void ShapeBuilder::UBuildPyramid(GLMesh& mesh)
{
	// build a pyramid

	float h = mesh.height;

	mesh.v = {
		// Vertex Positions    // color coords					// Texture coords
		 0.0f,	h,		0.0f,	0.0f,	1.0f,	-1.0f,	1.0f,	0.625f, 1.0f,		//back side
		 0.5f, -0.0f, -0.5f,	0.0f,	0.0f,	-1.0f,	1.0f,	0.50f, 0.0f,
		-0.5f, -0.0f, -0.5f,	0.0f,	0.0f,	-1.0f,	1.0f,	0.75f, 0.0f,

		 0.0f,  h,		0.0f,	-1.0f,	1.0f,	0.0f,	1.0f,	0.875f, 1.0f,		//left side
		-0.5f, -0.0f, -0.5f,	-1.0f,	0.0f,	0.0f,	1.0f,	0.75f, 0.0f,
		-0.5f, -0.0f,  0.5f,	-1.0f,	0.0f,	0.0f,	1.0f,	1.0f, 0.0f,

		 0.0f,  h,		0.0f,	0.0f,	1.0f,	1.0f,	1.0f,	0.125f, 1.0f,		//front
		-0.5f, -0.0f,  0.5f,	0.0f,	0.0f,	1.0f,	1.0f,	0.0f, 0.0f,
		 0.5f, -0.0f,  0.5f,	0.0f,	0.0f,	1.0f,	1.0f,	0.25f, 0.0f,

		 0.0f,  h,		0.0f,	1.0f,	1.0f,	0.0f,	1.0f,	0.375f, 1.0f,		//right side
		 0.5f, -0.0f,  0.5f,	1.0f,	0.0f,	0.0f,	1.0f,	0.25f, 0.0f,
		 0.5f, -0.0f, -0.5f,	1.0f,	0.0f,	0.0f,	1.0f,	0.50f, 0.0f,

		-0.5f, -0.0f, -0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.0f, 0.0f,		//bottom back
		 0.5f, -0.0f, -0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.25f, 0.0f,
		-0.5f, -0.0f,  0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.0f, 1.0f,

		 0.5f, -0.0f, -0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.25f, 0.0f,		//bottom front
		-0.5f, -0.0f,  0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.0f, 1.0f,
		 0.5f, -0.0f,  0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.25f, 1.0f
	};

	UTranslator(mesh);

}
void ShapeBuilder::UBuildCube(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	mesh.v = {
		0.5f,	0.0f,	0.5f,	0.0f,	0.0f,	1.0f,	1.0f,	0.25f,	0.5f,	// front left
		-0.5f,	0.0f,	0.5f,	0.0f,	0.0f,	1.0f,	1.0f,	0.0f,	0.5f,
		-0.5f,	1.0f,	0.5f,	0.0f,	0.0f,	1.0f,	1.0f,	0.0f,	1.0f,

		0.5f,	0.0f,	0.5f,	0.0f,	0.0f,	1.0f,	1.0f,	0.25f,	0.5f,	// front right
		0.5f,	1.0f,	0.5f,	0.0f,	0.0f,	1.0f,	1.0f,	0.25f,	1.0f,
		-0.5f,	1.0f,	0.5f,	0.0f,	0.0f,	1.0f,	1.0f,	0.0f,	1.0f,


		0.5f,	0.0f,	0.5f,	1.0f,	0.0f,	0.0f,	1.0f,	0.25f,	0.5f,	// right front
		0.5f,	1.0f,	0.5f,	1.0f,	0.0f,	0.0f,	1.0f,	0.25f,	1.0f,
		0.5f,	1.0f,	-0.5f,	1.0f,	0.0f,	0.0f,	1.0f,	0.5f,	1.0f,

		0.5f,	0.0f,	0.5f,	1.0f,	0.0f,	0.0f,	1.0f,	0.25f,	0.5f,	// right back
		0.5f,	0.0f,	-0.5f,	1.0f,	0.0f,	0.0f,	1.0f,	0.5f,	0.5f,
		0.5f,	1.0f,	-0.5f,	1.0f,	0.0f,	0.0f,	1.0f,	0.5f,	1.0f,


		0.5f,	0.0f,	-0.5f,	0.0f,	0.0f,	-1.0f,	1.0f,	0.5f,	0.5f,	// back left
		-0.5f,	0.0f,	-0.5f,	0.0f,	0.0f,	-1.0f,	1.0f,	0.75f,	0.5f,
		-0.5f,	1.0f,	-0.5f,	0.0f,	0.0f,	-1.0f,	1.0f,	0.75f,	1.0f,

		0.5f,	0.0f,	-0.5f,	0.0f,	0.0f,	-1.0f,	1.0f,	0.5f,	0.5f,	// back right
		0.5f,	1.0f,	-0.5f,	0.0f,	0.0f,	-1.0f,	1.0f,	0.5f,	1.0f,
		-0.5f,	1.0f,	-0.5f,	0.0f,	0.0f,	-1.0f,	1.0f,	0.75f,	1.0f,


		-0.5f,	0.0f,	0.5f,	-1.0f,	0.0f,	0.0f,	1.0f,	1.0f,	0.5f,	// left back
		-0.5f,	1.0f,	0.5f,	-1.0f,	0.0f,	0.0f,	1.0f,	1.0f,	1.0f,
		-0.5f,	1.0f,	-0.5f,	-1.0f,	0.0f,	0.0f,	1.0f,	0.75f,	1.0f,

		-0.5f,	0.0f,	0.5f,	-1.0f,	0.0f,	0.0f,	1.0f,	1.0f,	0.5f,	// left front
		-0.5f,	0.0f,	-0.5f,	-1.0f,	0.0f,	0.0f,	1.0f,	0.75f,	0.5f,
		-0.5f,	1.0f,	-0.5f,	-1.0f,	0.0f,	0.0f,	1.0f,	0.75f,	1.0f,




		-0.5f,	1.0f,	0.5f,	-0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	0.0f,	// top left
		-0.5f,	1.0f,	-0.5f,	-0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	0.5f,
		0.5f,	1.0f,	0.5f,	-0.0f,	1.0f,	0.0f,	1.0f,	0.25f,	0.0f,

		-0.5f,	1.0f,	-0.5f,	-0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	0.5f,	// top right
		0.5f,	1.0f,	0.5f,	-0.0f,	1.0f,	0.0f,	1.0f,	0.25f,	0.0f,
		0.5f,	1.0f,	-0.5f,	-0.0f,	1.0f,	0.0f,	1.0f,	0.25f,	0.5f,

		-0.5f,	0.0f,	0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.0f,	0.0f,	// bottom left
		-0.5f,	0.0f,	-0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.0f,	0.5f,
		0.5f,	0.0f,	0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.25f,	0.0f,

		-0.5f,	0.0f,	-0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.0f,	0.5f,	// bottom right
		0.5f,	0.0f,	0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.25f,	0.0f,
		0.5f,	0.0f,	-0.5f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.25f,	0.5f,

	};

	UTranslator(mesh);
}
void ShapeBuilder::UBuildCone(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	float r = mesh.radius;
	float h = mesh.height;
	float s = mesh.number_of_sides;

	constexpr float PI = 3.14f;
	const float sectorStep = 2.0f * PI / s;
	const float textStep = 1.0f / s;
	float textureXLoc = 0.0f;

	vector<float> v;

	for (auto i = 1; i < s + 1; i++) {

		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;


		// triangle fan, bottom
		//v.insert(v.end(), { 0.5f, 0.0f, 0.5f, c[0], -1.0f, c[2], c[3], 0.5f, 0.25f });		// center point; x, y, z, r, g, b, a, texture x, texture y
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,				// first outer point
										0.0f ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], -1.0f, c[2], c[3],
										/*textureXLoc,
										0.0f*/
										0.5f + (r * cos((i)*sectorStep)) ,			// texture x; adding the origin for proper alignment
										0.25f + (0.25f * sin((i)*sectorStep))
										});												
		v.insert(v.end(), { 0.5f + (r * cos((i + 1) * sectorStep)) ,		// second outer point
										0.0f ,
										0.5f + (r * sin((i + 1) * sectorStep)) ,
										c[0], -1.0f, c[2], c[3],
										/*textureXLoc + textStep,
										0.0f*/
										0.5f + (r * cos((i + 1) * sectorStep)) ,
										0.25f + (0.25f * sin((i + 1) * sectorStep))
										});												


		// side triangle + point
		v.insert(v.end(), { 0.5f + (r * cos(i * sectorStep)) ,
										0.0f ,
										0.5f + (r * sin(i * sectorStep)) ,
										c[0], 1.0f, c[2], c[3],
										textureXLoc ,
										0.5f });
		v.insert(v.end(), { 0.5f + (r * cos((i + 1) * sectorStep)) ,
										0.0f ,
										0.5f + (r * sin((i + 1) * sectorStep)) ,
										c[0], 1.0f, c[2], c[3],
										textureXLoc + textStep,
										0.5f });
		v.insert(v.end(), { 0.5f , h , 0.5f , c[0], 1.0f, c[2], c[3], textureXLoc + (textStep / 2), 1.0f });		// origin, peak

		textureXLoc += textStep;

	}

	mesh.v = v;
	v.clear();	// clear the local vector

	UTranslator(mesh);
}

void ShapeBuilder::UBuildCylinder(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	float r = mesh.radius;
	float h = mesh.height;
	float s = mesh.number_of_sides;


	constexpr float PI = 3.14f;
	const float sectorStep = 2.0f * PI / s;

	vector<float> v;

	for (auto i = 0; i < s; i++)
	{
		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;
		

		// triangle fan, bottom
		v.insert(v.end(), { 0.5f, 0.0f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.5f, 0.125f });			// origin (0.5, 0.5) works best for textures
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,			// x
										0.0f ,										// y
										0.5f + r * sin(i * sectorStep) ,			// z
										c[0], -1.0f, c[2], 1.0f,						// color data r g b a
										0.5f + (0.5f * cos((i)*sectorStep)) ,		// texture x; adding the origin for proper alignment
										(0.125f + (0.125f * sin((i)*sectorStep))) });		// texture y


		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										0.0f ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], -1.0f, c[2], 1.0f,						// color data r g b a
										0.5f + (0.5f * cos((i + 1) * sectorStep)) ,
										(0.125f + (0.125f * sin((i + 1) * sectorStep))) });


	}

	for (auto i = 1; i < s + 1; i++)
	{

		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;
		// triangle fan, top
		v.insert(v.end(), { 0.5f, h, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.5f, 0.875f });			// origin (0.5, 0.5) works best for textures
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										h ,										// build this fan the 'l' value away from the other fan
										0.5f + r * sin(i * sectorStep) ,
										c[0], 1.0f, c[2], 1.0f,					// color data r g b a
										0.5f + (0.5f * cos((i)*sectorStep)) ,
										0.875f + (0.125f * sin((i)*sectorStep)) });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 1.0f, c[2], 1.0f,					// color data r g b a
										0.5f + (0.5f * cos((i + 1) * sectorStep)) ,
										0.875f + (0.125f * sin((i + 1) * sectorStep)) });
	}

	// since all side triangles have the same points as the fans above, the same calculations are used
	// to wrap the texture around the cylinder, the calculated points are used to determine which section of
	// the texture to clamp to the corresponding point.
	constexpr float x = 1.0f;
	float j = 1.0f / (s / x);	// for calculating texture location; change 'x' to increase or decrease how many times the texture wraps around the cylinder
	float k = 0.0f;				// for texture clamping

	// sides
	for (auto i = 0; i < s; i++)
	{
		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;


		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										0.0f ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k ,
										0.25f });

		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										h ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k ,
										0.75f });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k + j ,
										0.75f });

		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k + j ,
										0.75f });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										0.0f ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k + j ,
										0.25f });

		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										0.0f ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k,
										0.25f });
		k += j;
	}

	mesh.v = v;
	v.clear();
	UTranslator(mesh);

}


void ShapeBuilder::UBuildHollowCylinder(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };
	
	float ir = mesh.innerRadius;
	float r = mesh.radius;
	float h = mesh.height;
	float s = mesh.number_of_sides;

	constexpr float PI = 3.14f;
	const float sectorStep = 2.0f * PI / s;

	vector<float> v;

	for (auto i = 0; i < s; i++)
	{

		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;


		// FOR TEXTURE COORDS
		// use distance formula
		// x2 = x1 + d * cos(theta)
		// y2 = y1 + d * sin(theta)
		//
		// x1 = 0.5, d = 0.5 for outer radius, always; d = (inner radius / outer radius * 0.5)
		// theta = i * sectorStep
		//
		// y1 = 0.125, d = 0.125 for outer radius, always; d = (inner radius / outer radius * 0.125)
		// theta = i * sectorStep
		//


		//BOTTOM OF HOLLOW CYLINDER
		v.insert(v.end(), { 0.5f + ir * cos(i * sectorStep) ,				
										0.0f ,												
										0.5f + ir * sin(i * sectorStep) ,				
										-c[0], -1.0f, -c[2], 1.0f,							
										0.5f + ((ir / r * 0.5f) * cos((i)*sectorStep)) ,	
										(0.125f + ((ir / r * 0.125f) * sin((i)*sectorStep))) });

		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,					// x
										0.0f ,												// y
										0.5f + r * sin(i * sectorStep) ,					// z
										c[0], -1.0f, c[2], 1.0f,							// color data r g b a
										0.5f + (0.5f * cos((i)*sectorStep)) ,			// texture x; adding the origin for proper alignment
										(0.125f + 0.125f * sin((i)*sectorStep)) });		// texture y

		v.insert(v.end(), { 0.5f + ir * cos((i + 1) * sectorStep) ,
										0.0f ,
										0.5f + ir * sin((i + 1) * sectorStep) ,
										-c[0], -1.0f, -c[2], 1.0f,							
										0.5f + ((ir / r * 0.5f) * cos((i + 1) * sectorStep)) ,
										(0.125f + ((ir / r * 0.125f) * sin((i + 1) * sectorStep))) });
		v.insert(v.end(), { 0.5f + ir * cos((i + 1) * sectorStep) ,
										0.0f ,
										0.5f + ir * sin((i + 1) * sectorStep) ,
										-c[0], -1.0f, -c[2], 1.0f,						
										0.5f + ((ir / r * 0.5f) * cos((i + 1) * sectorStep)) ,
										(0.125f + ((ir / r * 0.125f) * sin((i + 1) * sectorStep))) });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										0.0f ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], -1.0f, c[2], 1.0f,						
										0.5f + (0.5f * cos((i + 1) * sectorStep)) ,
										(0.125f + 0.125f * sin((i + 1) * sectorStep)) });
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,						
										0.0f ,										
										0.5f + r * sin(i * sectorStep) ,			
										c[0], -1.0f, c[2], 1.0f,						
										0.5f + (0.5f * cos((i)*sectorStep)) ,		
										(0.125f + (0.125f * sin((i)*sectorStep))) });

	}

	for (auto i = 0; i < s; i++)
	{
		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;

		//TOP OF HOLLOW CYLINDER
		v.insert(v.end(), { 0.5f + ir * cos(i * sectorStep) ,
										h ,
										0.5f + ir * sin(i * sectorStep) ,
										-c[0], 1.0f, -c[2], 1.0f,
										0.5f + ((ir / r * 0.5f) * cos((i)*sectorStep)) ,
										(0.125f + ((ir / r * 0.125f) * sin((i)*sectorStep))) });

		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,					// x
										h ,												// y
										0.5f + r * sin(i * sectorStep) ,					// z
										c[0], 1.0f, c[2], 1.0f,							// color data r g b a
										0.5f + (0.5f * cos((i)*sectorStep)) ,			// texture x; adding the origin for proper alignment
										(0.125f + 0.125f * sin((i)*sectorStep)) });		// texture y

		v.insert(v.end(), { 0.5f + ir * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + ir * sin((i + 1) * sectorStep) ,
										-c[0], 1.0f, -c[2], 1.0f,
										0.5f + ((ir / r * 0.5f) * cos((i + 1) * sectorStep)) ,
										(0.125f + ((ir / r * 0.125f) * sin((i + 1) * sectorStep))) });
		v.insert(v.end(), { 0.5f + ir * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + ir * sin((i + 1) * sectorStep) ,
										-c[0], 1.0f, -c[2], 1.0f,
										0.5f + ((ir / r * 0.5f) * cos((i + 1) * sectorStep)) ,
										(0.125f + ((ir / r * 0.125f) * sin((i + 1) * sectorStep))) });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 1.0f, c[2], 1.0f,
										0.5f + (0.5f * cos((i + 1) * sectorStep)) ,
										(0.125f + 0.125f * sin((i + 1) * sectorStep)) });
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										h ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], 1.0f, c[2], 1.0f,
										0.5f + (0.5f * cos((i)*sectorStep)) ,
										(0.125f + (0.125f * sin((i)*sectorStep))) });

	}

	constexpr float x = 1.0f;
	float j = 1.0f / (s / x);	// for calculating texture location; change 'x' to increase or decrease how many times the texture wraps around the cylinder
	float k = 0.0f;				// for texture clamping


	// OUTSIDE SIDES OF HOLLOW CYLINDER
	for (auto i = 0; i < s; i++)
	{
		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;


		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										0.0f ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k ,
										0.25f });

		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										h ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k ,
										0.75f });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k + j ,
										0.75f });

		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k + j ,
										0.75f });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										0.0f ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k + j ,
										0.25f });

		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										0.0f ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], 0.0f, c[2], c[3],					// color data r g b a
										k,
										0.25f });
		k += j;
	}

	// INSIDE SIDES OF HOLLOW CYLINDER
	for (auto i = 0; i < s; i++)
	{
		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;


		v.insert(v.end(), { 0.5f + ir * cos(i * sectorStep) ,
										0.0f ,
										0.5f + ir * sin(i * sectorStep) ,
										-c[0], 0.0f, -c[2], c[3],					// color data r g b a
										k ,
										0.25f });

		v.insert(v.end(), { 0.5f + ir * cos(i * sectorStep) ,
										h ,
										0.5f + ir * sin(i * sectorStep) ,
										-c[0], 0.0f, -c[2], c[3],					// color data r g b a
										k ,
										0.75f });
		v.insert(v.end(), { 0.5f + ir * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + ir * sin((i + 1) * sectorStep) ,
										-c[0], 0.0f, -c[2], c[3],					// color data r g b a
										k + j ,
										0.75f });

		v.insert(v.end(), { 0.5f + ir * cos((i + 1) * sectorStep) ,
										h ,
										0.5f + ir * sin((i + 1) * sectorStep) ,
										-c[0], 0.0f, -c[2], c[3],					// color data r g b a
										k + j ,
										0.75f });
		v.insert(v.end(), { 0.5f + ir * cos((i + 1) * sectorStep) ,
										0.0f ,
										0.5f + ir * sin((i + 1) * sectorStep) ,
										-c[0], 0.0f, -c[2], c[3],					// color data r g b a
										k + j ,
										0.25f });

		v.insert(v.end(), { 0.5f + ir * cos(i * sectorStep) ,
										0.0f ,
										0.5f + ir * sin(i * sectorStep) ,
										-c[0], 0.0f, -c[2], c[3],					// color data r g b a
										k,
										0.25f });
		k += j;
	}




	mesh.v = v;

	UTranslator(mesh);

}

void ShapeBuilder::UBuildPlane(GLMesh& mesh)
{
	// Use this to build the ground, for proper lighting
	
	mesh.v = {

		-1.0f,	0.0f,	-1.0f,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	1.0f,	// 0
		 0.0f,	0.0f,	 1.0f,	0.0f,	1.0f,	0.0f,	1.0f,	0.5f,	0.0f,	// 1
		-1.0f,	0.0f,	 1.0f,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	0.0f,	// 2

		-1.0f,	0.0f,	-1.0f, 	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	1.0f,	// 0
		 0.0f,	0.0f,	 1.0f,	0.0f,	1.0f,	0.0f,	1.0f,	0.5f,	0.0f,	// 2
		 0.0f,	0.0f,	-1.0f, 	0.0f,	1.0f,	0.0f,	1.0f,	0.5f,	1.0f,	// 3

		 0.0f,	0.0f,	-1.0f, 	0.0f,	1.0f,	0.0f,	1.0f,	0.5f,	1.0f,	// 3
		 0.0f,	0.0f,	 1.0f, 	0.0f,	1.0f,	0.0f,	1.0f,	0.5f,	0.0f,	// 2
		 1.0f,	0.0f,	 1.0f, 	0.0f,	1.0f,	0.0f,	1.0f,	1.0f,	0.0f,	// 5

		 0.0f,	0.0f,	-1.0f, 	0.0f,	1.0f,	0.0f,	1.0f,	0.5f,	1.0f,	// 3
		 1.0f,	0.0f,	 1.0f, 	0.0f,	1.0f,	0.0f,	1.0f,	1.0f,	0.0f,	// 5
		 1.0f,	0.0f,	-1.0f, 	0.0f,	1.0f,	0.0f,	1.0f,	1.0f,	1.0f,	// 4

	};

	UTranslator(mesh);

}

void ShapeBuilder::UBuildCircle(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };


	float r = mesh.radius;
	float l = mesh.length;
	float s = mesh.number_of_sides;
	float h = mesh.height;

	constexpr float PI = 3.14f;
	const float sectorStep = 2.0f * PI / s;

	vector<float> v;

	

	for (auto i = 1; i < s + 1; i++)
	{

		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;

		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;
		// triangle fan, top
		v.insert(v.end(), { 0.5f, 0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.5f, 0.5f });			// origin (0.5, 0.5) works best for textures
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
										0.0f ,										// build this fan the 'l' value away from the other fan
										0.5f + r * sin(i * sectorStep) ,
										c[0], 1.0f, c[2], 1.0f,					// color data r g b a
										0.5f + (0.5f * cos((i)*sectorStep)) ,
										0.5f + (0.5f * sin((i)*sectorStep)) });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
										0.0f ,
										0.5f + r * sin((i + 1) * sectorStep) ,
										c[0], 1.0f, c[2], 1.0f,					// color data r g b a
										0.5f + (0.5f * cos((i + 1) * sectorStep)) ,
										0.5f + (0.5f * sin((i + 1) * sectorStep)) });
	}
	mesh.v = v;
	v.clear();
	UTranslator(mesh);
}


void ShapeBuilder::UBuildGarbage(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	float r = mesh.radius;
	float h = mesh.height;
	float s = mesh.number_of_sides;

	constexpr float PI = 3.14159f;


	auto sphere_point = [PI](float u, float v) {
		float r = std::sin(PI * v);
		return vector<float>{
			r * std::cos(2.0f * PI * u),
			r * std::sin(2.0f * PI * u),
			std::cos(PI * v),
			u,
			v
		};
	};

	vector<float> v;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < s; j++) {

			float u0 = (float)i / (float)h;
			float u1 = (float)(i + 1) / (float)h;
			float v0 = (float)j / (float)s;
			float v1 = (float)(j + 1) / float(s);

			// Create quad as two triangles.
			v.push_back(sphere_point(u0, v0)[0]);
			v.push_back(sphere_point(u0, v0)[1]);
			v.push_back(sphere_point(u0, v0)[2]);
			v.push_back(sphere_point(u0, v0)[3]);
			v.push_back(sphere_point(u0, v0)[4]);

			v.push_back(sphere_point(u1, v0)[0]);
			v.push_back(sphere_point(u1, v0)[1]);
			v.push_back(sphere_point(u1, v0)[2]);
			v.push_back(sphere_point(u1, v0)[3]);
			v.push_back(sphere_point(u1, v0)[4]);

			v.push_back(sphere_point(u0, v1)[0]);
			v.push_back(sphere_point(u0, v1)[1]);
			v.push_back(sphere_point(u0, v1)[2]);
			v.push_back(sphere_point(u0, v1)[3]);
			v.push_back(sphere_point(u0, v1)[4]);

			v.push_back(sphere_point(u0, v1)[0]);
			v.push_back(sphere_point(u0, v1)[1]);
			v.push_back(sphere_point(u0, v1)[2]);
			v.push_back(sphere_point(u0, v1)[3]);
			v.push_back(sphere_point(u0, v1)[4]);

			v.push_back(sphere_point(u1, v0)[0]);
			v.push_back(sphere_point(u1, v0)[1]);
			v.push_back(sphere_point(u1, v0)[2]);
			v.push_back(sphere_point(u1, v0)[3]);
			v.push_back(sphere_point(u1, v0)[4]);

			v.push_back(sphere_point(u1, v1)[0]);
			v.push_back(sphere_point(u1, v1)[1]);
			v.push_back(sphere_point(u1, v1)[2]);
			v.push_back(sphere_point(u1, v1)[3]);
			v.push_back(sphere_point(u1, v1)[4]);
		}
	}

	mesh.v = v;
	v.clear();
	UTranslator(mesh);
}


void ShapeBuilder::UBuildHalfSphere(GLMesh& mesh)
{
	const float radius = mesh.radius;
	const unsigned int rings = mesh.rings;
	const unsigned int sectors = mesh.sectors;
	const float M_PI = 3.14159f;

	mesh.v.clear();

	for (unsigned int r = 0; r < rings / 2; ++r) // Divided rings by 2 to make half sphere
	{
		for (unsigned int s = 0; s < sectors ; ++s)
		{
			for (unsigned int i = 0; i < 2; ++i) // repeat twice
			{
				// we add + i to the r and s to draw the next vertex in the quad
				const float y = sin(-M_PI / 2 + M_PI * (r + i) / (rings - 1));
				for (unsigned int j = 0; j < 2; ++j) // repeat twice
				{
					const float x = cos(2 * M_PI * (s + j) / sectors) * sin(M_PI * (r + i) / (rings - 1));
					const float z = sin(2 * M_PI * (s + j) / sectors) * sin(M_PI * (r + i) / (rings - 1));

					// vertex position
					mesh.v.push_back(x * radius);
					mesh.v.push_back(y * radius);
					mesh.v.push_back(z * radius);

					// color (from p array)
					mesh.v.push_back(mesh.p[0]); // r
					mesh.v.push_back(mesh.p[1]); // g
					mesh.v.push_back(mesh.p[2]); // b
					mesh.v.push_back(mesh.p[3]); // a

					// texture coordinates
					mesh.v.push_back((s + j) / (float)sectors); // u
					mesh.v.push_back((r + i) / (float)(rings - 1)); // v
				}
			}
		}
	}

	UTranslator(mesh);
}

void ShapeBuilder::UBuildSphere(GLMesh& mesh)
{
	const float radius = mesh.radius;
	const unsigned int rings = mesh.rings;
	const unsigned int sectors = mesh.sectors;
	const float M_PI = 3.14159f;

	mesh.v.clear();

	for (unsigned int r = 0; r < rings - 1; ++r) // don't need to calculate the last points, they are created by the first ring
	{
		for (unsigned int s = 0; s < sectors; ++s)
		{
			for (unsigned int i = 0; i < 2; ++i) // repeat twice
			{
				// we add + i to the r and s to draw the next vertex in the quad
				const float y = sin(-M_PI / 2 + M_PI * (r + i) / (rings - 1));
				for (unsigned int j = 0; j < 2; ++j) // repeat twice
				{
					const float x = cos(2 * M_PI * (s + j) / sectors) * sin(M_PI * (r + i) / (rings - 1));
					const float z = sin(2 * M_PI * (s + j) / sectors) * sin(M_PI * (r + i) / (rings - 1));

					// vertex position
					mesh.v.push_back(x * radius);
					mesh.v.push_back(y * radius);
					mesh.v.push_back(z * radius);

					// color (from p array)
					mesh.v.push_back(mesh.p[0]); // r
					mesh.v.push_back(mesh.p[1]); // g
					mesh.v.push_back(mesh.p[2]); // b
					mesh.v.push_back(mesh.p[3]); // a

					// texture coordinates
					mesh.v.push_back((s + j) / (float)sectors); // u
					mesh.v.push_back((r + i) / (float)(rings - 1)); // v
				}
			}
		}
	}

	UTranslator(mesh);
}

// Template for creating a cube light
void ShapeBuilder::UCreateLightMesh(GLMesh& lightMesh)
{
	// Position and Color data
	GLfloat verts[] = {
		//Positions          //Normals
		// ------------------------------------------------------
		//Back Face          //Negative Z Normal  Texture Coords.
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		//Front Face         //Positive Z Normal
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,

		//Left Face          //Negative X Normal
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		//Right Face         //Positive X Normal
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		//Bottom Face        //Negative Y Normal
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		//Top Face           //Positive Y Normal
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	const GLuint floatsPerVertex = 3;
	const GLuint floatsPerNormal = 3;
	const GLuint floatsPerUV = 2;

	lightMesh.nIndices = sizeof(verts) / (sizeof(verts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));

	glGenVertexArrays(1, &lightMesh.vao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(lightMesh.vao);

	// Create 2 buffers: first one for the vertex data; second one for the indices
	glGenBuffers(1, &lightMesh.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, lightMesh.vbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

	// Strides between vertex coordinates is 6 (x, y, z, r, g, b, a). A tightly packed stride is 0.
	GLint stride = sizeof(float) * (floatsPerVertex + floatsPerNormal + floatsPerUV);// The number of floats before each

	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * floatsPerVertex));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
}


// Standard translate method to move, rotate, and resize the shape
void ShapeBuilder::UTranslator(GLMesh& mesh)
{
	// build the mesh

	constexpr GLuint floatsPerVertex = 3;
	constexpr GLuint floatsPerColor = 4;
	constexpr GLuint floatsPerUV = 2;

	
	mesh.nIndices = mesh.v.size() / (floatsPerVertex + floatsPerUV + floatsPerColor);
	

	glGenVertexArrays(1, &mesh.vao);
	glBindVertexArray(mesh.vao);

	// Create VBO
	glGenBuffers(1, &mesh.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo); // Activates the buffer

	// use vector instead of array
	glBufferData(
		GL_ARRAY_BUFFER,
		mesh.v.size() * sizeof(float),
		&mesh.v.front(),
		GL_STATIC_DRAW
	); // Sends vertex or coordinate data to the GPU

	// Strides between vertex coordinates
	constexpr GLint stride = sizeof(float) * (floatsPerVertex + floatsPerUV + floatsPerColor);

	

	// Create Vertex Attribute Pointers
	// location
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);

	if (mesh.color) {
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	}

	// color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);


	// scale the object
	mesh.scale = glm::scale(glm::vec3(mesh.p[4], mesh.p[5], mesh.p[6]));

	const glm::mat4 rot = glm::mat4(1.0f);

	// rotate the object (x, y, z) (0 - 6.4, to the right)
	mesh.xrotation = glm::rotate(rot, glm::radians(mesh.p[7]), glm::vec3(mesh.p[8], mesh.p[9], mesh.p[10]));
	mesh.yrotation = glm::rotate(rot, glm::radians(mesh.p[11]), glm::vec3(mesh.p[12], mesh.p[13], mesh.p[14]));
	mesh.zrotation = glm::rotate(rot, glm::radians(mesh.p[15]), glm::vec3(mesh.p[16], mesh.p[17], mesh.p[18]));


	// move the object (x, y, z)
	mesh.translation = glm::translate(glm::vec3(mesh.p[19], mesh.p[20], mesh.p[21]));

	mesh.model = mesh.translation * mesh.xrotation * mesh.zrotation * mesh.yrotation * mesh.scale;

	mesh.gUVScale = glm::vec2(mesh.p[22], mesh.p[23]);		// scales the texture

	

}
