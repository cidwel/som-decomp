.setcpu "65816"
.segment "CODE"
.org $1BDA
map_control_0f1bda:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
