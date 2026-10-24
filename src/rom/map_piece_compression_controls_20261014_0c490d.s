.setcpu "65816"
.segment "CODE"
.org $490D
map_control_0c490d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
