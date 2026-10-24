.setcpu "65816"
.segment "CODE"
.org $4445
map_control_0c4445:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E6 ; previous-row copy count
