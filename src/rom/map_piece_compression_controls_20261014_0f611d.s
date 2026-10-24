.setcpu "65816"
.segment "CODE"
.org $611D
map_control_0f611d:
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
