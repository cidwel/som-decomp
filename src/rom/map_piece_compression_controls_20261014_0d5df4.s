.setcpu "65816"
.segment "CODE"
.org $5DF4
map_control_0d5df4:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
    .byte $E2 ; previous-row copy count
