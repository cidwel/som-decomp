.setcpu "65816"
.segment "CODE"
.org $4C12
map_control_0d4c12:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E1 ; previous-row copy count
