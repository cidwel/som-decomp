.setcpu "65816"
.segment "CODE"
.org $5012
map_control_0d5012:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
