.setcpu "65816"
.segment "CODE"
.org $09CA
map_control_0e09ca:
    .byte $F6 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
