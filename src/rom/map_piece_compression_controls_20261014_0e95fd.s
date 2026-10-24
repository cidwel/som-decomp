.setcpu "65816"
.segment "CODE"
.org $95FD
map_control_0e95fd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
