.setcpu "65816"
.segment "CODE"
.org $002B
map_control_0e002b:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
