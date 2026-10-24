.setcpu "65816"
.segment "CODE"
.org $1901
map_control_0e1901:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
