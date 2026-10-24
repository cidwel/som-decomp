.setcpu "65816"
.segment "CODE"
.org $DADA
map_control_0edada:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $D1 ; same-value copy count/distance
