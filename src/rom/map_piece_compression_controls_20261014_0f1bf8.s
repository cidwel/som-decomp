.setcpu "65816"
.segment "CODE"
.org $1BF8
map_control_0f1bf8:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
