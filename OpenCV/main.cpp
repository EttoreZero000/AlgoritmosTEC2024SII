#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture capture(0);  // Captura desde la cámara (cámara 0)
    if (!capture.isOpened()) {
        std::cerr << "Error al abrir la cámara." << std::endl;
        return -1;
    }

    cv::Mat prevGray, gray, frame;
    std::vector<cv::Point2f> prevPoints, nextPoints;
    std::vector<uchar> status;
    std::vector<float> err;

    // Leer el primer frame y convertirlo a escala de grises
    capture >> frame;
    cv::cvtColor(frame, prevGray, cv::COLOR_BGR2GRAY);

    // Detectar características en la primera imagen
    cv::goodFeaturesToTrack(prevGray, prevPoints, 100, 0.3, 7);

    while (true) {
        // Capturar el siguiente frame
        capture >> frame;
        if (frame.empty()) break;

        // Convertir a escala de grises
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // Calcular el flujo óptico usando el método de Lucas-Kanade
        cv::calcOpticalFlowPyrLK(prevGray, gray, prevPoints, nextPoints, status, err);

        // Dibujar las líneas del flujo óptico
        for (size_t i = 0; i < nextPoints.size(); i++) {
            if (status[i]) {
                cv::line(frame, prevPoints[i], nextPoints[i], cv::Scalar(0, 255, 0), 2);
                cv::circle(frame, nextPoints[i], 5, cv::Scalar(0, 0, 255), -1);
            }
        }

        // Mostrar el frame con el flujo óptico
        cv::imshow("Optical Flow", frame);

        // Salir si se presiona la tecla 'q'
        if (cv::waitKey(30) == 'q') break;

        // Actualizar la imagen previa y los puntos
        prevGray = gray.clone();
        prevPoints = nextPoints;
    }

    capture.release();
    cv::destroyAllWindows();
    return 0;
}
