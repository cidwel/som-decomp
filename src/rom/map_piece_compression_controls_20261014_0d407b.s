.setcpu "65816"
.segment "CODE"
.org $407B
map_control_0d407b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
