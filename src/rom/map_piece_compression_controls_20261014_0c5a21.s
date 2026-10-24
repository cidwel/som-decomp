.setcpu "65816"
.segment "CODE"
.org $5A21
map_control_0c5a21:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
