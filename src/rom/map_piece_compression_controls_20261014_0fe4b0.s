.setcpu "65816"
.segment "CODE"
.org $E4B0
map_control_0fe4b0:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
