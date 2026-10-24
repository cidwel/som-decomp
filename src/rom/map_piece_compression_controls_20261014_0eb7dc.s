.setcpu "65816"
.segment "CODE"
.org $B7DC
map_control_0eb7dc:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
