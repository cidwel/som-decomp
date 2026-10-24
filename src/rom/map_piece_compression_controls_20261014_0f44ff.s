.setcpu "65816"
.segment "CODE"
.org $44FF
map_control_0f44ff:
    .byte $C2 ; same-value copy count/distance
