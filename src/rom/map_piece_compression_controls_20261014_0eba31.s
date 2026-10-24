.setcpu "65816"
.segment "CODE"
.org $BA31
map_control_0eba31:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
