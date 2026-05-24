.PHONY: all menu clean

CXX = g++
CXXFLAGS = -Wall -O2 -I./punto1_pendulo_elastico/include -I./punto2_fenomenologia/include

# Colores estándar
AZUL     = \033[34m
VERDE    = \033[32m
AMARILLO = \033[33m
ROJO     = \033[31m
RESET    = \033[0m

all: menu

menu:
    @clear
    @echo -e "$(AZUL)=== SIMULACIÓN CIENTÍFICA ===$(RESET)"
    @echo -e " 1) Péndulo elástico"
    @echo -e " 2) Depredador-Presa (Lotka-Volterra)"
    @echo -e " 3) Salir"
    @echo "-----------------------------"
    @echo -ne "$(AMARILLO)Seleccione opción [1-3]: $(RESET)"; \
    read opcion; \
    if [ "$$opcion" = "1" ]; then \
        $(MAKE) pendulo; \
    elif [ "$$opcion" = "2" ]; then \
        $(MAKE) depredador_presa; \
    elif [ "$$opcion" = "3" ]; then \
        echo -e "\n¡Hasta luego!"; \
    else \
        echo -e "$(ROJO)Opción inválida.$(RESET)"; \
        sleep 1; $(MAKE) menu; \
    fi

pendulo:
    @echo -e "\n$(AZUL)► Compilando péndulo elástico...$(RESET)"
    @mkdir -p punto1_pendulo_elastico/results/graficas
    @$(CXX) $(CXXFLAGS) -o punto1_pendulo_elastico/pendulo.exe \
        punto1_pendulo_elastico/src/main.cpp \
        punto1_pendulo_elastico/src/pendulo_elastico.cpp
    @echo -e "$(AZUL)► Ejecutando simulación...$(RESET)"
    @cd punto1_pendulo_elastico && ./pendulo.exe
    @$(MAKE) graficar_pendulo

depredador_presa:
    @echo -e "\n$(AZUL)► Compilando modelo Depredador-Presa...$(RESET)"
    @mkdir -p punto2_fenomenologia/results/graficas
    @$(CXX) $(CXXFLAGS) -o punto2_fenomenologia/fenomenologia.exe \
        punto2_fenomenologia/src/main.cpp \
        punto2_fenomenologia/src/fenomenologia.cpp \
        punto2_fenomenologia/src/rk4.cpp \
        punto2_fenomenologia/src/derivadas.cpp
    @echo -e "$(AZUL)► Ejecutando simulación...$(RESET)"
    @cd punto2_fenomenologia && ./fenomenologia.exe
    @$(MAKE) graficar_depredador_presa

graficar_pendulo:
    @echo -e "\n$(AZUL)=== OPCIONES DE GRAFICACIÓN ===$(RESET)"
    @echo " 1) Gnuplot"
    @echo " 2) Python"
    @echo "-------------------------------"
    @echo -ne "$(AMARILLO)Seleccione motor [1-2]: $(RESET)"; \
    read grafica; \
    if [ "$$grafica" = "1" ]; then \
        cd punto1_pendulo_elastico && gnuplot scripts/graficar_gnuplot.gp; \
        echo -e "$(VERDE)✔ Gráfica guardada en results/graficas/pendulo_elastico.png$(RESET)\n"; \
    elif [ "$$grafica" = "2" ]; then \
        cd punto1_pendulo_elastico && python3 scripts/graficar_python.py; \
    else \
        echo -e "$(ROJO)Opción inválida. No se graficó.$(RESET)\n"; \
    fi

graficar_depredador_presa:
    @echo -e "\n$(AZUL)=== OPCIONES DE GRAFICACIÓN ===$(RESET)"
    @echo " 1) Gnuplot"
    @echo " 2) Python"
    @echo "-------------------------------"
    @echo -ne "$(AMARILLO)Seleccione motor [1-2]: $(RESET)"; \
    read grafica; \
    if [ "$$grafica" = "1" ]; then \
        cd punto2_fenomenologia && gnuplot scripts/graficar_gnuplot.gp; \
        echo -e "$(VERDE)✔ Gráfica guardada en results/graficas/fenomenologia.png$(RESET)\n"; \
    elif [ "$$grafica" = "2" ]; then \
        cd punto2_fenomenologia && python3 scripts/graficar_python.py; \
    else \
        echo -e "$(ROJO)Opción inválida. No se graficó.$(RESET)\n"; \
    fi

clean:
    @echo "Limpiando archivos..."
    @rm -f punto1_pendulo_elastico/pendulo.exe punto2_fenomenologia/fenomenologia.exe
    @rm -f punto1_pendulo_elastico/results/*.dat punto2_fenomenologia/results/*.dat
    @rm -rf punto1_pendulo_elastico/results/graficas/*.png punto2_fenomenologia/results/graficas/*.png
    @echo -e "$(VERDE)Limpieza completada.$(RESET)"

