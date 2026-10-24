.setcpu "65816"
.segment "CODE"
.org $4955
map_control_0c4955:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
