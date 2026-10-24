.setcpu "65816"
.segment "CODE"
.org $B100
map_control_0fb100:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
