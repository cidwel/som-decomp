.setcpu "65816"
.segment "CODE"
.org $3397
map_control_0d3397:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
