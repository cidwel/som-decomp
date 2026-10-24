.setcpu "65816"
.segment "CODE"
.org $8B2F
map_control_0c8b2f:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
