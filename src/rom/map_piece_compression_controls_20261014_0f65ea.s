.setcpu "65816"
.segment "CODE"
.org $65EA
map_control_0f65ea:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
