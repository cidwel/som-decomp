.setcpu "65816"
.segment "CODE"
.org $85A4
map_control_0d85a4:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
