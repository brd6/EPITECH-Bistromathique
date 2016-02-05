# EPITECH - Bistromathique

Ce projet consiste à créer un programme capable d'effectuer des opérations arithmétiques sur des nombres dont l'ordre de grandeur n'est pas fixe et dans une base quelconque.
Il a été réalisé par groupe de 3.

# Usage

usage :  ./calc base operators size_read

# Exemples

echo "3+6" | ./calc 0123456789 "()+-*/%" 3
echo "3v6" | ./calc 0123456789 "{}vwxyz" 3
echo "-(12-(4*32))" | ./calc 0123456789 "()+-*/%" 12
echo "-(e@-(;*!@))" | ./calc "~^@!;ie& ]" "()+-*/%" 13