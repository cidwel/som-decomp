.setcpu "65816"
.segment "CODE"
.org $AFFC
map_control_0daffc:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
