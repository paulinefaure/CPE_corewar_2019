#
# EPITECH PROJECT, 2019
# CPE_corewar_2019
# File description:
# champion.s for corewar
#

.name "BOB"
.comment "basic living program"

l2:
sti r1,%:live, %1
and r1, %0, r1
live: live %1
zjmp %:live