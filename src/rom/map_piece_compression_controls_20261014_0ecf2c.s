.setcpu "65816"
.segment "CODE"
.org $CF2C
map_control_0ecf2c:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
