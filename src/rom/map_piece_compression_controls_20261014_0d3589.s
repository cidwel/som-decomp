.setcpu "65816"
.segment "CODE"
.org $3589
map_control_0d3589:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
