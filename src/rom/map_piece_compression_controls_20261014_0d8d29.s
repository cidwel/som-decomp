.setcpu "65816"
.segment "CODE"
.org $8D29
map_control_0d8d29:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
