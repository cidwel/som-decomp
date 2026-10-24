.setcpu "65816"
.segment "CODE"
.org $F122
map_control_0ff122:
    .byte $D9 ; same-value copy count/distance
