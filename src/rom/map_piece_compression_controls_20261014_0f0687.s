.setcpu "65816"
.segment "CODE"
.org $0687
map_control_0f0687:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
