.setcpu "65816"
.segment "CODE"
.org $4497
map_control_0e4497:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
