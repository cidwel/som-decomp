.setcpu "65816"
.segment "CODE"
.org $56AC
map_control_0f56ac:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
