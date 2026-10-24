.setcpu "65816"
.segment "CODE"
.org $DEBD
map_control_0edebd:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
