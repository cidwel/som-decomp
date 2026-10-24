.setcpu "65816"
.segment "CODE"
.org $9122
map_control_0d9122:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
