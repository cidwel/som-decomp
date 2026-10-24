.setcpu "65816"
.segment "CODE"
.org $CE7C
map_control_0ece7c:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
