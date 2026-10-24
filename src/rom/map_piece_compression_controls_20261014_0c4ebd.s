.setcpu "65816"
.segment "CODE"
.org $4EBD
map_control_0c4ebd:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
