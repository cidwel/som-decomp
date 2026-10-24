.setcpu "65816"
.segment "CODE"
.org $3482
map_control_0e3482:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
    .byte $E5 ; previous-row copy count
