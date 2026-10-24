.setcpu "65816"
.segment "CODE"
.org $8BA3
map_control_0e8ba3:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
