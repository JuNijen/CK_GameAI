#pragma once
class StrategeDesignedCameraman
{
};

class Cameraman
{
	iCameraInterface* myCam;

	void setCamera(iCameraInterface* cam);
	void useCamera();
};

__interface iCameraInterface
{
	virtual void takePicture();
};

class Camera1 : public iCameraInterface 
{
	void takePicture();
};

class Camera2 : public iCameraInterface
{
	void takePicture();
};

void Cameraman::setCamera(iCameraInterface* cam)
{
	myCam = cam;
}

void Cameraman::useCamera()
{
	myCam->takePicture();
}