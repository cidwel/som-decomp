.setcpu "65816"
.segment "CODE"
.org $9273
map_control_0d9273:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $3B ; distance low bit/count
