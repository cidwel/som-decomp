.setcpu "65816"
.segment "CODE"
.org $939D
map_control_0e939d:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
