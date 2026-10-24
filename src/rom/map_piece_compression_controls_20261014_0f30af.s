.setcpu "65816"
.segment "CODE"
.org $30AF
map_control_0f30af:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
