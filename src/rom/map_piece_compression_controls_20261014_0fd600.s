.setcpu "65816"
.segment "CODE"
.org $D600
map_control_0fd600:
    .byte $C3 ; same-value copy count/distance
