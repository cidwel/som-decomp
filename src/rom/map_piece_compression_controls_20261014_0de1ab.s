.setcpu "65816"
.segment "CODE"
.org $E1AB
map_control_0de1ab:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
