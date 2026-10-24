.setcpu "65816"
.segment "CODE"
.org $30CB
map_control_0f30cb:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
