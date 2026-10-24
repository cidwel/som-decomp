.setcpu "65816"
.segment "CODE"
.org $7F7F
map_control_0c7f7f:
    .byte $E2 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
