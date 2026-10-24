.setcpu "65816"
.segment "CODE"
.org $7658
map_control_0c7658:
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
