.setcpu "65816"
.segment "CODE"
.org $30C7
map_control_0f30c7:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
