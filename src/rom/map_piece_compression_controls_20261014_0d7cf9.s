.setcpu "65816"
.segment "CODE"
.org $7CF9
map_control_0d7cf9:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E1 ; previous-row copy count
