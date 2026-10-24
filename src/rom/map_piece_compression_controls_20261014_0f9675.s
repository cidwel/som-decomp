.setcpu "65816"
.segment "CODE"
.org $9675
map_control_0f9675:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
