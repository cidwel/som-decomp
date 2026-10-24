.setcpu "65816"
.segment "CODE"
.org $B959
map_control_0fb959:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $5B ; distance low bit/count
