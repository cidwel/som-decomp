.setcpu "65816"
.segment "CODE"
.org $5765
map_control_0c5765:
    .byte $F2 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
