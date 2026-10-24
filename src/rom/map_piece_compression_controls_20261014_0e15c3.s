.setcpu "65816"
.segment "CODE"
.org $15C3
map_control_0e15c3:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
