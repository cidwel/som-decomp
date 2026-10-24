.setcpu "65816"
.segment "CODE"
.org $639D
map_control_0c639d:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
