.setcpu "65816"
.segment "CODE"
.org $DBBE
map_control_0edbbe:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E6 ; previous-row copy count
