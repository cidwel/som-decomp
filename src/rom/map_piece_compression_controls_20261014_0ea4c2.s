.setcpu "65816"
.segment "CODE"
.org $A4C2
map_control_0ea4c2:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
