.setcpu "65816"
.segment "CODE"
.org $85C7
map_control_0f85c7:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
