.setcpu "65816"
.segment "CODE"
.org $9292
map_control_0c9292:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
