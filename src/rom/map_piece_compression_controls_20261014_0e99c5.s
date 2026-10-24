.setcpu "65816"
.segment "CODE"
.org $99C5
map_control_0e99c5:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
