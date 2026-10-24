.setcpu "65816"
.segment "CODE"
.org $CDDA
map_control_0ecdda:
    .byte $C2 ; same-value copy count/distance
