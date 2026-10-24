.setcpu "65816"
.segment "CODE"
.org $F367
map_control_0ff367:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
