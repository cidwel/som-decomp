.setcpu "65816"
.segment "CODE"
.org $CE92
map_control_0ece92:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
