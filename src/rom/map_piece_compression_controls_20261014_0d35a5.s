.setcpu "65816"
.segment "CODE"
.org $35A5
map_control_0d35a5:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
