.setcpu "65816"
.segment "CODE"
.org $C2AF
map_control_0dc2af:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
