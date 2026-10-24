.setcpu "65816"
.segment "CODE"
.org $5012
map_control_0c5012:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
