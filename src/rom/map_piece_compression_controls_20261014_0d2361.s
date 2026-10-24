.setcpu "65816"
.segment "CODE"
.org $2361
map_control_0d2361:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
