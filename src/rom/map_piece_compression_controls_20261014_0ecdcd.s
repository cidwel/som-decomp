.setcpu "65816"
.segment "CODE"
.org $CDCD
map_control_0ecdcd:
    .byte $C5 ; same-value copy count/distance
