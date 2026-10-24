.setcpu "65816"
.segment "CODE"
.org $B280
map_control_0fb280:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
