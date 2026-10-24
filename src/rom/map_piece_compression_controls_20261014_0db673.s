.setcpu "65816"
.segment "CODE"
.org $B673
map_control_0db673:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
