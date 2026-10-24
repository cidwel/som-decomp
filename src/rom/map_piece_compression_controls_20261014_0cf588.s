.setcpu "65816"
.segment "CODE"
.org $F588
map_control_0cf588:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
