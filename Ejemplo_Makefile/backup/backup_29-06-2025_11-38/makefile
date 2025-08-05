################################################################
# Author: Leandro Schiavoni
# Organización de archivos fuente en .inc (.h) y .src (.c)
# Uso: Pararse en el directorio raíz y hacer: make callex
################################################################

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = out
BIN_DIR = bin
BUP_DIR = backup

# Nombre del ejecutable = nombre del directorio actual
TARGET  = $(BIN_DIR)/$(notdir $(shell pwd))

SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))
CFLAGS  = -Wall -Wextra -I$(INC_DIR)

# Para debug: imprime los archivos fuente y objetos
print:
	@echo "Archivos fuente: $(SRCS)"
	@echo "Archivos objeto: $(OBJS)"

# Regla principal: compilar y linkear
all: $(TARGET)

call: clean all
	
callex: call ex

# Backup con fecha/hora en formato dia-mes-año_hora-min
.PHONY: backup
backup:
	@mkdir -p $(BUP_DIR)
	@fecha=$$(date +"%d-%m-%Y_%H-%M"); \
	mkdir -p $(BUP_DIR)/backup_$$fecha; \
	cp -rf $(SRC_DIR) $(INC_DIR) makefile $(BUP_DIR)/backup_$$fecha; \
	echo "Backup generado en $(BUP_DIR)/backup_$$fecha"

# Compilación final
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)

# Compilación individual de .c -> .o
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc -c -MD $(CFLAGS) $< -o $@

# Inclusión automática de dependencias generadas con -MD
-include $(OBJ_DIR)/*.d

# Eliminar ejecutables y objetos
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

# Ejecutar binario si existe
ex:
	@if [ -f $(TARGET) ]; then \
		echo "Ejecutando $(TARGET)"; \
		./$(TARGET); \
	else \
		echo "Error: no se encontró $(TARGET). Compilá con 'make'"; \
	fi
