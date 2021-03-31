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
#       $ ./norme.sh -m dir1 [dir2] [dir3] [dir...]
#       $ ./norme.sh -r     
#
#   Opções são:
#       -m | --multiple     Executa a verificação da norminette nos diretórios
#                               inclusos nos argumentos, deve existir ao menos
#                               um diretório passado por argumento.
#       -r | --recursive    Executa a verificação da norminette em todos os
#                               diretórios recursivamente.
#
#   Importate: Norminette só verifica arquivos com extensão "*.c" ou "*.h"







