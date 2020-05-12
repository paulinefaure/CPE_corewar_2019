
rm zaz.* me.*

read -p 'Quel fichier veux tu comparer ? : ' path

echo $path
cp $path zaz.s
cp $path me.s
../../asm_zaz zaz.s
../../asm me.s > /dev/null
if [ $? != 0 ]
then
	exit;
fi
hexdump zaz.cor > zaz.txt
hexdump me.cor > me.txt
diff me.txt zaz.txt
if [ $? != 0 ]
then
	echo $path
	exit;
fi
rm -f zaz.s me.s zaz.txt me.txt
