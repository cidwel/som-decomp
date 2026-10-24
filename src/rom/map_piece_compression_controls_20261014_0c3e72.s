.setcpu "65816"
.segment "CODE"
.org $3E72
map_control_0c3e72:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $72 ; distance low bit/count
