.setcpu "65816"
.segment "CODE"
.org $9ED7
map_control_0d9ed7:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
