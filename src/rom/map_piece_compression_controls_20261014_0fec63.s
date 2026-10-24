.setcpu "65816"
.segment "CODE"
.org $EC63
map_control_0fec63:
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
