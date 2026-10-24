.setcpu "65816"
.segment "CODE"
.org $B321
map_control_0eb321:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
