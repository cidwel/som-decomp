.setcpu "65816"
.segment "CODE"
.org $DE6E
map_control_0fde6e:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
