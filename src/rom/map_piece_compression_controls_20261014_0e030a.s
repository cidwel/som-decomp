.setcpu "65816"
.segment "CODE"
.org $030A
map_control_0e030a:
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E6 ; previous-row copy count
