.setcpu "65816"
.segment "CODE"
.org $CEEA
map_control_0eceea:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
