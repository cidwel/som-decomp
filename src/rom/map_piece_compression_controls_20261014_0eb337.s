.setcpu "65816"
.segment "CODE"
.org $B337
map_control_0eb337:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
