.setcpu "65816"
.segment "CODE"
.org $8BA3
map_control_0f8ba3:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
