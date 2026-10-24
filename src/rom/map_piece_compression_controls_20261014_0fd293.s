.setcpu "65816"
.segment "CODE"
.org $D293
map_control_0fd293:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
