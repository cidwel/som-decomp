.setcpu "65816"
.segment "CODE"
.org $3F11
map_control_0d3f11:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
