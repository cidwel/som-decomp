.setcpu "65816"
.segment "CODE"
.org $F450
map_control_0ef450:
    .byte $E6 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
