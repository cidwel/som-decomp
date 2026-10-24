.setcpu "65816"
.segment "CODE"
.org $7F22
map_control_0d7f22:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
