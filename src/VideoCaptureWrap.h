#include "OpenCV.h"

#ifdef HAVE_OPENCV_VIDEOIO

class VideoCaptureWrap: public Nan::ObjectWrap {
public:
  cv::VideoCapture cap;

  static Nan::Persistent<FunctionTemplate> constructor;
  static void Init(Local<Object> target);
  static NAN_METHOD(New);

  VideoCaptureWrap(const std::string& filename);
  VideoCaptureWrap(int device);

  static NAN_METHOD(Read);
  static NAN_METHOD(ReadSync);

  static NAN_METHOD(Grab);
  static NAN_METHOD(Retrieve);

  // For getting width and height of the input video stream
  static NAN_METHOD(GetWidth);
  static NAN_METHOD(GetHeight);

  // (Optional) For setting width and height of the input video stream
  static NAN_METHOD(SetWidth);
  static NAN_METHOD(SetHeight);

  // to set frame position
  static NAN_METHOD(SetPosition);
  static NAN_METHOD(GetFrameCount);

  static NAN_METHOD(GetFPS);
  static NAN_METHOD(SetFPS);

  static NAN_METHOD(GetFrameAt);

  // release the stream
  static NAN_METHOD(Release);
};

#endif
