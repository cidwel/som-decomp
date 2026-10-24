.setcpu "65816"
.segment "CODE"
.org $09B0
map_control_0e09b0:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
