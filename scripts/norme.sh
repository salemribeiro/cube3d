#!/bin/bash
# 
# norme.sh  -   Verifica se todos os *.c *.h estão de acordo com a norma
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
#       $ ./norme.sh [dir]
#   Importate: Norminette só verifica arquivos com extensão "*.c" ou "*.h"

norminetteC="~/.norminette/norminette.rb *.c"
norminetteH="~/.norminette/norminette.rb *.c"

if [ -z $1 ]; then
    echo "Erro - argumentos são esperados"
    exit 1;
fi

origem=$(pwd)

if [ -d $1 ]; then
    echo "Aplicando a norma no diretório"
        cd $1
        $norminetteC > "$origem/norme.logc"
        $norminetteH > "$origem/norme.logh"
        cd $origem
        if grep -c "Error" "$origem/norme.logc"; then
             echo "Erro ao verificar a norma!"
             echo "consulte os arquivos de log"
             exit 1
        fi
else
    echo "Erro - Diretório não existe"
    exit 1;
fi
echo "Sucesso!!!"
exit 0

