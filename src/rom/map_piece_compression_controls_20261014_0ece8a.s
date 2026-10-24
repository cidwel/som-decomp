.setcpu "65816"
.segment "CODE"
.org $CE8A
map_control_0ece8a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
