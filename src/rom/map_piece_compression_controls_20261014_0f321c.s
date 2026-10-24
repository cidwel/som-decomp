.setcpu "65816"
.segment "CODE"
.org $321C
map_control_0f321c:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E2 ; previous-row copy count
