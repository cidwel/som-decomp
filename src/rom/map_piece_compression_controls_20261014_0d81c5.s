.setcpu "65816"
.segment "CODE"
.org $81C5
map_control_0d81c5:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
