.setcpu "65816"
.segment "CODE"
.org $4D5B
map_control_0f4d5b:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
