.setcpu "65816"
.segment "CODE"
.org $3B5A
map_control_0d3b5a:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
