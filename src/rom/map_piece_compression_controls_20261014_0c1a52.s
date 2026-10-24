.setcpu "65816"
.segment "CODE"
.org $1A52
map_control_0c1a52:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
