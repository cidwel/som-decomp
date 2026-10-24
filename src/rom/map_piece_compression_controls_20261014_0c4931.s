.setcpu "65816"
.segment "CODE"
.org $4931
map_control_0c4931:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
