.setcpu "65816"
.segment "CODE"
.org $BCBC
map_control_0fbcbc:
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
