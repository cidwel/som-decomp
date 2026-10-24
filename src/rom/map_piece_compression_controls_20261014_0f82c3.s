.setcpu "65816"
.segment "CODE"
.org $82C3
map_control_0f82c3:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E3 ; previous-row copy count
