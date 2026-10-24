.setcpu "65816"
.segment "CODE"
.org $9EE3
map_control_0e9ee3:
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
