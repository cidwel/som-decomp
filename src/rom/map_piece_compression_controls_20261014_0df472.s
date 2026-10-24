.setcpu "65816"
.segment "CODE"
.org $F472
map_control_0df472:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
