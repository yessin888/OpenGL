#ifndef __IGVCAMARA
#define __IGVCAMARA

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvPunto3D.h"
typedef enum {
	panoramica,
	planta,
	perfil,
	alzado,
}poscam;

typedef enum {
	IGV_PARALELA,
	IGV_FRUSTUM,
	IGV_PERSPECTIVA
} tipoCamara;

class igvCamara {

public:
	// atributos
	poscam vis;		// Posici�n de la c�mara

	tipoCamara tipo;	// paralela o perspectiva

	// ventana de visi�n: parametros proyecci�n paralela y frustum
	GLdouble xwmin, xwmax, ywmin, ywmax;

	// ventana de visi�n: parametros proyecci�n perspectiva
	GLdouble 	angulo, raspecto;

	// distancias de planos cercano y lejano
	GLdouble znear, zfar;

	// punto de visi�n	
	igvPunto3D P0;

	// punto de referencia de visi�n	
	igvPunto3D r;

	// vector arriba	
	igvPunto3D V;

	float factor = 1;
	// Metodos

public:
	// Constructores por defecto y destructor
	igvCamara();
	~igvCamara();

	//cambiar tipo de c�mara
	void setTipoCamara(tipoCamara camara);

	// Otros constructores
	igvCamara(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V);

	// Metodos
	// define la posici�n de la c�mara
	void set(igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V);

	// define una c�mara de tipo paralela o frustum
	void set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
		double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar);

	// define una c�mara de tipo perspectiva
	void set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
		double _angulo, double _raspecto, double _znear, double _zfar);

	void aplicar();

	void zoom(double factor); // realiza un zoom sobre la c�mara

	void set_vista(tipoCamara t) { tipo = t; };
	tipoCamara get_vista() { return tipo; };
	void set_poscam(poscam x) { vis = x; };
	poscam get_poscam() { return vis; };

	//C�mara y distancias
	void sumarZnear();
	void restarZnear(); 		// asociadas a los par�metros de la c�mara 
	void zoomOut();
	void zoom();

	//mover camara de posicion
	void maszP0(float a);
	void menoszP0(float a);
	void masyP0(float a);
	void menosyP0(float a);
	void masxP0(float a);
	void menosxP0(float a);

	//movimiento panoramico
	void panoramica(float a);
	void cabeceo(float a);

};

#endif

