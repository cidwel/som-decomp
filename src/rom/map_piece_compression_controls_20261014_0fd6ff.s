.setcpu "65816"
.segment "CODE"
.org $D6FF
map_control_0fd6ff:
    .byte $C2 ; same-value copy count/distance
