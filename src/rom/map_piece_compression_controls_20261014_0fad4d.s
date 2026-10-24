.setcpu "65816"
.segment "CODE"
.org $AD4D
map_control_0fad4d:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E7 ; previous-row copy count
