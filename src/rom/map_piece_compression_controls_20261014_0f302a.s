.setcpu "65816"
.segment "CODE"
.org $302A
map_control_0f302a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
