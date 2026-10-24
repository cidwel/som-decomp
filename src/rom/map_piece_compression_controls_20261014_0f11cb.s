.setcpu "65816"
.segment "CODE"
.org $11CB
map_control_0f11cb:
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
