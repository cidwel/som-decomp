.setcpu "65816"
.segment "CODE"
.org $CBB7
map_control_0dcbb7:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
