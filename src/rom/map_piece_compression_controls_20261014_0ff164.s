.setcpu "65816"
.segment "CODE"
.org $F164
map_control_0ff164:
    .byte $C2 ; same-value copy count/distance
