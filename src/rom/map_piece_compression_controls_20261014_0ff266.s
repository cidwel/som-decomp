.setcpu "65816"
.segment "CODE"
.org $F266
map_control_0ff266:
    .byte $C3 ; same-value copy count/distance
