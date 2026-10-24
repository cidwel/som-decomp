.setcpu "65816"
.segment "CODE"
.org $EF81
map_control_0eef81:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
