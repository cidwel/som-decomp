.setcpu "65816"
.segment "CODE"
.org $D0A5
map_control_0fd0a5:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
