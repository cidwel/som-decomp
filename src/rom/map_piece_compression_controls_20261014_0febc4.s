.setcpu "65816"
.segment "CODE"
.org $EBC4
map_control_0febc4:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
