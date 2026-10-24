.setcpu "65816"
.segment "CODE"
.org $1238
map_control_0c1238:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
