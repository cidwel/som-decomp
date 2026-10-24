.setcpu "65816"
.segment "CODE"
.org $975F
map_control_0e975f:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
