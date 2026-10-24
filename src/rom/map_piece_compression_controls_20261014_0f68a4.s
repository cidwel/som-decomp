.setcpu "65816"
.segment "CODE"
.org $68A4
map_control_0f68a4:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
