.setcpu "65816"
.segment "CODE"
.org $501A
map_control_0f501a:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
