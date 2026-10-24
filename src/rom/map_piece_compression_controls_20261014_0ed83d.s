.setcpu "65816"
.segment "CODE"
.org $D83D
map_control_0ed83d:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
