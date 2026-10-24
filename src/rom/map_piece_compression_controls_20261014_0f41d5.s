.setcpu "65816"
.segment "CODE"
.org $41D5
map_control_0f41d5:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
