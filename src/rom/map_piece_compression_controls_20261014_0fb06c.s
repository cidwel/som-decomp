.setcpu "65816"
.segment "CODE"
.org $B06C
map_control_0fb06c:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E6 ; previous-row copy count
