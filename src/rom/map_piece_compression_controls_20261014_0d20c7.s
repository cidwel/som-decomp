.setcpu "65816"
.segment "CODE"
.org $20C7
map_control_0d20c7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
