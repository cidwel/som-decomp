.setcpu "65816"
.segment "CODE"
.org $B9DC
map_control_0fb9dc:
    .byte $E9 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E7 ; previous-row copy count
