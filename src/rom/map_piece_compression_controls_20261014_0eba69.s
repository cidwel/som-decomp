.setcpu "65816"
.segment "CODE"
.org $BA69
map_control_0eba69:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
