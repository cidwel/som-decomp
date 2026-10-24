.setcpu "65816"
.segment "CODE"
.org $8633
map_control_0f8633:
    .byte $F2 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
