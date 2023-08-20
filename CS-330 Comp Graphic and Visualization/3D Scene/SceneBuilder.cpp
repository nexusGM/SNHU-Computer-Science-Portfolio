///
///	This class is designed to be the one place where all
///	shapes are created. It utilizes the UShapeBuilder class
///	to build the shapes into GLMesh structs.
///
///
///	Follow the standard shown below in the <summary> to see
///	how to build a shape
///




#include "SceneBuilder.h"
#include "ShapeBuilder.h"
#include "Headers/Mesh.h"

using namespace std;


void SceneBuilder::UBuildScene(vector<GLMesh>& scene)
{




	// seed the rand() function once
	srand(time(nullptr));


	/// <summary>
	///
	///BUILDING A SHAPE:
	///To build a shape, follow the following standard:
	///
	///		GLMesh <glmesh_name>
	///		<glmesh_name>.p = {
	///		red float, green float, blue float, alpha float,
	///		x scale float, y scale float, z scale float,
	///		x rotation degrees float, 1.0f, 0.0f, 0.0f,
	///		y rotation degrees float, 0.0f, 1.0f, 0.0f,
	///		z rotation degrees float, 0.0f, 0.0f, 1.0f,
	///		x translate float, y translate float, z translate float,
	///		x texture scale float, y texture scale float
	///		};
	///		<glmesh_name>.texFilename = "textures\\[filename.filetype]";
	///		<glmesh_name>.length = float;
	///		<glmesh_name>.height = float;
	///		<glmesh_name>.radius = float;
	///		<glmesh_name>.number_of_sides = float;
	///		ShapeBuilder::<ShapeBuilderMethod>(<glmesh_name>);
	///		**OR**
	///		ShapeBuilder::<ShapeBuild "Rainbow" Shape>(<glmesh_name>, rand() % 100 + 1);
	///		scene.push_back(<glmesh_name>);
	///
	///
	///
	///		See below for an example using the UBuildCone() method
	///
	///
	/// </summary>
	/// <param name="scene"></param>


	// Desk
	GLMesh plan_gMesh01;
	plan_gMesh01.p = {
		1.0f,  1.0f, 1.0f, 1.0f,			// color r, g, b a
		10.0f,  1.0f, 5.0f,					// scale x, y, z
		0.0f,  1.0f, 0.0f, 0.0f,			// x amount of rotation, rotate x, y, z
		225.0f, 0.0f, 1.0f, 0.0f,			// y amount of rotation, rotate x, y, z
		0.0f,  0.0f, 0.0f, 1.0f,			// z amount of rotation, rotate x, y, z
		1.0f,  0.0f, 0.0f,					// translate x, y, z
		1.0f,  1.0f
	};
	plan_gMesh01.texFilename = "textures\\space.jpg";
	ShapeBuilder::UBuildPlane(plan_gMesh01);
	scene.push_back(plan_gMesh01);


	// Cube
	GLMesh cube;
	cube.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		1.5f,	1.5f,	1.5f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-110.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		2.0f,	0.1f,	-2.0f,
		1.0f,	1.0f
	};
	cube.texFilename = "textures\\cube.png";
	ShapeBuilder::UBuildCube(cube);
	scene.push_back(cube);
	
	// Garbage
	GLMesh garbage;
	garbage.p = {
		1.0f,  1.0f, 1.0f, 1.0f,			// color r, g, b a
		1.0f, 1.0f, 1.0f,					// scale x, y, z
		0.0f,  1.0f, 0.0f, 0.0f,			// x amount of rotation, rotate x, y, z
		45.0f, 0.0f, 1.0f, 0.0f,			// y amount of rotation, rotate x, y, z
		0.0f,  0.0f, 0.0f, 1.0f,			// z amount of rotation, rotate x, y, z
		0.5f,  0.5f, 2.0f,					// translate x, y, z
		1.0f,  1.0f
	};
	garbage.height = 10.0;
	garbage.radius = 10.0;
	garbage.number_of_sides = 10.0;
	garbage.texFilename = "textures\\paper.jpg";
	ShapeBuilder::UBuildGarbage(garbage);
	scene.push_back(garbage);

	// Pokeball
	GLMesh pokeball_bottom;
	pokeball_bottom.p = {
		1.0f,  1.0f, 1.0f, 1.0f, // color r, g, b a
		0.5f, 0.5f, 0.5f,         // scale x, y, z
		0.0f,  1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		0.0f,  0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		-2.0f,  1.0f, 2.0f,        // translate x, y, z
		1.0f,  1.0f
	};
	pokeball_bottom.rings = 30;
	pokeball_bottom.radius = 2.0;
	pokeball_bottom.sectors = 30;
	pokeball_bottom.texFilename = "textures\\pokeball.jpg";
	ShapeBuilder::UBuildHalfSphere(pokeball_bottom);
	scene.push_back(pokeball_bottom);

	// Pokeball
	GLMesh pokeball_top;
	pokeball_top.p = {
		1.0f,  1.0f, 1.0f, 1.0f, // color r, g, b a
		0.5f, 0.5f, 0.5f,         // scale x, y, z
		180.0f,  1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		90.0f,  0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		-1.05f,  1.95f, 2.0f,        // translate x, y, z
		1.0f,  1.0f
	};
	pokeball_top.rings = 30;
	pokeball_top.radius = 2.0;
	pokeball_top.sectors = 30;
	pokeball_top.texFilename = "textures\\pokeball2.jpg";
	ShapeBuilder::UBuildHalfSphere(pokeball_top);
	scene.push_back(pokeball_top);

	// Card
	GLMesh card;
	card.p = {
		1.0f, 1.0f, 1.0f, 1.0f, // color r, g, b a
		1.6f, 0.15f, 1.1f,         // scale x, y, z
		180.0f, 1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		-55.0f, 0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		-1.75f, 1.20f, 2.0f,        // translate x, y, z
		1.0f, 1.0f
	};
	card.texFilename = "textures\\mewtwo.png";
	ShapeBuilder::UBuildCube(card);
	scene.push_back(card);

	// Lamp Shade
	GLMesh lamp_shade;
	lamp_shade.p = {
		1.0f, 1.0f, 1.0f, 1.0f, // color r, g, b a
		1.0f, 1.0f, 1.0f,         // scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		-25.0f, 0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		4.6f, 3.5f, -5.0f,        // translate x, y, z
		1.0f, 1.0f
	};
	lamp_shade.radius = 1.5;
	lamp_shade.height = 2.0;
	lamp_shade.number_of_sides = 50;

	lamp_shade.texFilename = "textures\\black_metal.jpg";
	ShapeBuilder::UBuildCone(lamp_shade);
	scene.push_back(lamp_shade);

	// Lamp Arm
	GLMesh lamp_arm1;
	lamp_arm1.p = {
		1.0f, 1.0f, 1.0f, 1.0f, // color r, g, b a
		1.0f, 1.0f, 1.0f,         // scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		-115.0f, 0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		6.00f, 5.0f, -5.0f,        // translate x, y, z
		1.0f, 1.0f
	};
	lamp_arm1.radius = 0.05;
	lamp_arm1.height = 3.5;
	lamp_arm1.number_of_sides = 50;
	lamp_arm1.texFilename = "textures\\black_metal.jpg";
	ShapeBuilder::UBuildCylinder(lamp_arm1);
	scene.push_back(lamp_arm1);

	// Lamp Arm2
	GLMesh lamp_arm3;
	lamp_arm3.p = {
		1.0f, 1.0f, 1.0f, 1.0f, // color r, g, b a
		1.0f, 1.0f, 1.0f,         // scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		-115.0f, 0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		6.0f, 5.5f, -5.0f,        // translate x, y, z
		1.0f, 1.0f
	};
	lamp_arm3.radius = 0.05;
	lamp_arm3.height = 3.5;
	lamp_arm3.number_of_sides = 50;
	lamp_arm3.texFilename = "textures\\black_metal.jpg";
	ShapeBuilder::UBuildCylinder(lamp_arm3);
	scene.push_back(lamp_arm3);

	// Lamp Arm3
	GLMesh lamp_arm2;
	lamp_arm2.p = {
		1.0f, 1.0f, 1.0f, 1.0f, // color r, g, b a
		1.0f, 1.0f, 1.0f,         // scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		8.0f, 0.0f, -5.0f,        // translate x, y, z
		1.0f, 1.0f
	};
	lamp_arm2.radius = 0.15;
	lamp_arm2.height = 4.0;
	lamp_arm2.number_of_sides = 50;
	lamp_arm2.texFilename = "textures\\black_metal.jpg";
	ShapeBuilder::UBuildCylinder(lamp_arm2);
	scene.push_back(lamp_arm2);

	// Lamp Base
	GLMesh lamp_base;
	lamp_base.p = {
		1.0f, 1.0f, 1.0f, 1.0f, // color r, g, b a
		1.0f, 1.0f, 1.0f,         // scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		8.0f, 0.0f, -5.0f,        // translate x, y, z
		1.0f, 1.0f
	};
	lamp_base.radius = 1.5;
	lamp_base.height = 0.3;
	lamp_base.number_of_sides = 50;

	lamp_base.texFilename = "textures\\black_metal.jpg";
	ShapeBuilder::UBuildCone(lamp_base);
	scene.push_back(lamp_base);

	// Lamp Bulb
	
	GLMesh lamp_bulb;
	lamp_bulb.p = {
		1.0f,  1.0f, 1.0f, 1.0f, // color r, g, b a
		0.25f, 0.25f, 0.25f,         // scale x, y, z
		0.0f,  1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		0.0f,  0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		5.1f, 3.5f, -4.5f,        // translate x, y, z
		1.0f,  1.0f
	};
	lamp_bulb.rings = 30;
	lamp_bulb.radius = 2.0;
	lamp_bulb.sectors = 30;
	lamp_bulb.color = true;
	lamp_bulb.texFilename = "textures\\light_bulb.jpg";
	ShapeBuilder::UBuildSphere(lamp_bulb);
	scene.push_back(lamp_bulb);

	// Bulb Stem
	GLMesh bulb_stem;
	bulb_stem.p = {
		1.0f,  1.0f, 1.0f, 1.0f, // color r, g, b a
		1.0f, 1.0f, 1.0f,         // scale x, y, z
		0.0f,  1.0f, 0.0f, 0.0f,  // x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,  // y amount of rotation, rotate x, y, z
		0.0f,  0.0f, 0.0f, 1.0f,  // z amount of rotation, rotate x, y, z
		4.6f, 3.5f, -5.0f,        // translate x, y, z
		1.0f,  1.0f
	};
	bulb_stem.radius = 0.25;
	bulb_stem.height = 1.0;
	bulb_stem.number_of_sides = 50;
	bulb_stem.texFilename = "textures\\light_bulb.jpg";
	ShapeBuilder::UBuildCylinder(bulb_stem);
	scene.push_back(bulb_stem);


}

