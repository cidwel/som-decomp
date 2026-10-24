.setcpu "65816"
.segment "CODE"
.org $AA23
map_control_0eaa23:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
