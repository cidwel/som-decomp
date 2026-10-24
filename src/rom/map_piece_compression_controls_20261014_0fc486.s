.setcpu "65816"
.segment "CODE"
.org $C486
map_control_0fc486:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
