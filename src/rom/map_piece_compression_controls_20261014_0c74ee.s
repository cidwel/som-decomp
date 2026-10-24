.setcpu "65816"
.segment "CODE"
.org $74EE
map_control_0c74ee:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
