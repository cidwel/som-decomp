.setcpu "65816"
.segment "CODE"
.org $B4E7
map_control_0eb4e7:
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E5 ; previous-row copy count
