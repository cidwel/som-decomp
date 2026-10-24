.setcpu "65816"
.segment "CODE"
.org $DFD6
map_control_0fdfd6:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
    .byte $E1 ; previous-row copy count
