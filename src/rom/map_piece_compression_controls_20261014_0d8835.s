.setcpu "65816"
.segment "CODE"
.org $8835
map_control_0d8835:
    .byte $E8 ; backreference distance high bits
    .byte $4D ; distance low bit/count
