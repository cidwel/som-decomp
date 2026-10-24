.setcpu "65816"
.segment "CODE"
.org $95F3
map_control_0d95f3:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
