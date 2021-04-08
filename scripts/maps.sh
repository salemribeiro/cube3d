#!/bin/bash
# 
# maps.sh  -    Verifica se todos os *.c *.h estão de acordo com a norma
#               imposta pela escola 42.
#
#   github      - https://github.com/salemribeiro
#   Autor       - Salem Ribeiro
#   Manutenção  - Salem Ribeiro
#
#------------------------------------------------------------------------------
#
#   Software desenvolvido para ajuda na automação de testes dentro e fora do
#   de CI/CD e utilizei de seu desenvolvimento no aprimoramento do conhecimento
#   sobre scripts e CI/CD.
#
#   Exemplos:
#       $ ./maps.sh [caminho do executavel][caminho do mapa][return number]


if [ -z "$1" ]; then
	echo "Erro - argumentos são esperados"
	exit 1;
fi

if [ -z "$2" ]; then
	echo "Erro - argumentos são esperados"
	exit 1;
fi

if [ -z "$3" ]; then
	echo "Erro - argumentos são esperados"
	exit 1;
fi

if [ -e "$1" ]; then
	echo "Arquivo executavel encontrado"
	if [ -e "$2" ]; then
		echo "Mapa encontrado"
		eval "$1 $2"
		if [ "$?" -eq "$3" ]; then
			echo "Programa executou de maneira correta"
			exit 0;
		else
			echo "Teste deveria retornar o erro $3"
			exit 1
		fi
	else
        echo "Mapa não encontrado"
        exit 1;   
    fi
else
    echo "Erro - Arquivo executavel não encontrado"
    exit 1;
fi
echo "Sucesso!!!"
exit 0


