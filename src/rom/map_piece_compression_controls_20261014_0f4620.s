.setcpu "65816"
.segment "CODE"
.org $4620
map_control_0f4620:
    .byte $F2 ; progressive-copy count
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
