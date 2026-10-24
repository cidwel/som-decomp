.setcpu "65816"
.segment "CODE"
.org $30CF
map_control_0f30cf:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
