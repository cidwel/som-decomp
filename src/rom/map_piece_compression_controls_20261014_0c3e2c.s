.setcpu "65816"
.segment "CODE"
.org $3E2C
map_control_0c3e2c:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
