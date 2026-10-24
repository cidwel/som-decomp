.setcpu "65816"
.segment "CODE"
.org $0B9B
map_control_0f0b9b:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
