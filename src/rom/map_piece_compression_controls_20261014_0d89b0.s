.setcpu "65816"
.segment "CODE"
.org $89B0
map_control_0d89b0:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
