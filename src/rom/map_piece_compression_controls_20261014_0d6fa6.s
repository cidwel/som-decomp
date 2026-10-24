.setcpu "65816"
.segment "CODE"
.org $6FA6
map_control_0d6fa6:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
