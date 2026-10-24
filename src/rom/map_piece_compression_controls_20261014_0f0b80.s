.setcpu "65816"
.segment "CODE"
.org $0B80
map_control_0f0b80:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
