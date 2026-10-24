.setcpu "65816"
.segment "CODE"
.org $993C
map_control_0e993c:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
