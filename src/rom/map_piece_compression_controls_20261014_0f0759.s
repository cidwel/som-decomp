.setcpu "65816"
.segment "CODE"
.org $0759
map_control_0f0759:
    .byte $E6 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
