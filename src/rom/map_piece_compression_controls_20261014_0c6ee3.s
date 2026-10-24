.setcpu "65816"
.segment "CODE"
.org $6EE3
map_control_0c6ee3:
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
