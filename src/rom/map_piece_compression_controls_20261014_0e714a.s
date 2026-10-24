.setcpu "65816"
.segment "CODE"
.org $714A
map_control_0e714a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E5 ; previous-row copy count
