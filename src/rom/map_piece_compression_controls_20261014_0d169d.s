.setcpu "65816"
.segment "CODE"
.org $169D
map_control_0d169d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
