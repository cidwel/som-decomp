.setcpu "65816"
.segment "CODE"
.org $AB35
map_control_0fab35:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E3 ; previous-row copy count
