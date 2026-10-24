.setcpu "65816"
.segment "CODE"
.org $77BC
map_control_0f77bc:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
