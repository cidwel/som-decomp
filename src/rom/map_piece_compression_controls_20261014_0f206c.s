.setcpu "65816"
.segment "CODE"
.org $206C
map_control_0f206c:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E7 ; previous-row copy count
