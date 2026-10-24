.setcpu "65816"
.segment "CODE"
.org $1078
map_control_0d1078:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
