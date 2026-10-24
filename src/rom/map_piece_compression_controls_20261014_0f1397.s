.setcpu "65816"
.segment "CODE"
.org $1397
map_control_0f1397:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
