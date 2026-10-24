.setcpu "65816"
.segment "CODE"
.org $5D69
map_control_0f5d69:
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E6 ; previous-row copy count
