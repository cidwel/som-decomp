.setcpu "65816"
.segment "CODE"
.org $D6BB
map_control_0dd6bb:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
