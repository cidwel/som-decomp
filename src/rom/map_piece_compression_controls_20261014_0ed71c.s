.setcpu "65816"
.segment "CODE"
.org $D71C
map_control_0ed71c:
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E6 ; previous-row copy count
