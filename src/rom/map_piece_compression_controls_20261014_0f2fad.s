.setcpu "65816"
.segment "CODE"
.org $2FAD
map_control_0f2fad:
    .byte $C3 ; same-value copy count/distance
