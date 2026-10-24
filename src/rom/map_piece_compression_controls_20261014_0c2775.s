.setcpu "65816"
.segment "CODE"
.org $2775
map_control_0c2775:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
