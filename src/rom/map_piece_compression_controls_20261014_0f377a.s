.setcpu "65816"
.segment "CODE"
.org $377A
map_control_0f377a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
