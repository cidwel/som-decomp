.setcpu "65816"
.segment "CODE"
.org $68DE
map_control_0d68de:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E1 ; previous-row copy count
