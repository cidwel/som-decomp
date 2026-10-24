.setcpu "65816"
.segment "CODE"
.org $993C
map_control_0f993c:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
