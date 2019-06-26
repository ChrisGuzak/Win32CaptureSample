#pragma once
#include "SimpleCapture.h"

class App
{
public:
    App(winrt::Windows::UI::Composition::ContainerVisual root,
        winrt::Windows::Graphics::Capture::GraphicsCapturePicker picker);
    ~App() {}

    winrt::Windows::Graphics::Capture::GraphicsCaptureItem StartCaptureFromWindowHandle(HWND hwnd);
    winrt::Windows::Graphics::Capture::GraphicsCaptureItem StartCaptureFromMonitorHandle(HMONITOR hmon);
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Graphics::Capture::GraphicsCaptureItem> StartCaptureWithPickerAsync();

    void StopCapture();

private:
    void StartCaptureFromItem(winrt::Windows::Graphics::Capture::GraphicsCaptureItem item);

private:
    winrt::Windows::UI::Composition::Compositor m_compositor{ nullptr };
    winrt::Windows::UI::Composition::ContainerVisual m_root{ nullptr };
    winrt::Windows::UI::Composition::SpriteVisual m_content{ nullptr };
    winrt::Windows::UI::Composition::CompositionSurfaceBrush m_brush{ nullptr };

    winrt::Windows::Graphics::Capture::GraphicsCapturePicker m_picker{ nullptr };

    winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice m_device{ nullptr };
    std::unique_ptr<SimpleCapture> m_capture{ nullptr };
};