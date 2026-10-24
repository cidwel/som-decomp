.setcpu "65816"
.segment "CODE"
.org $254D
map_control_0d254d:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E4 ; previous-row copy count
