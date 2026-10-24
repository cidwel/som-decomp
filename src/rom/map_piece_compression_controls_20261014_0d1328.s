.setcpu "65816"
.segment "CODE"
.org $1328
map_control_0d1328:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E1 ; previous-row copy count
