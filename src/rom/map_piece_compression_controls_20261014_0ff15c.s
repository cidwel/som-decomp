.setcpu "65816"
.segment "CODE"
.org $F15C
map_control_0ff15c:
    .byte $C5 ; same-value copy count/distance
