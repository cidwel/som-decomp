.setcpu "65816"
.segment "CODE"
.org $5994
map_control_0d5994:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
