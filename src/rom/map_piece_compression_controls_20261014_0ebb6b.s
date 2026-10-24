.setcpu "65816"
.segment "CODE"
.org $BB6B
map_control_0ebb6b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
