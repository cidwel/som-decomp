.setcpu "65816"
.segment "CODE"
.org $F550
map_control_0ef550:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
