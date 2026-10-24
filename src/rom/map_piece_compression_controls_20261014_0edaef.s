.setcpu "65816"
.segment "CODE"
.org $DAEF
map_control_0edaef:
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E6 ; previous-row copy count
