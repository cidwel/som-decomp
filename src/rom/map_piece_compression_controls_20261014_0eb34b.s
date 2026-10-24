.setcpu "65816"
.segment "CODE"
.org $B34B
map_control_0eb34b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
