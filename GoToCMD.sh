#!/bin/bash

if [ $(whoami) != "root" ]
then
	echo -e "Vous devez exécuter ce script en mode sudo"
	exit 1
fi

if [[ -z "$(dpkg -s make | grep Status)" ]]
	then
		echo -e "Veuillez installer make pour executer ce script"
        exit 1
fi

cp MMF /bin
mv MMF /sbin
echo Adieu Monde cruel !
clear
rm GoToCMD.sh
