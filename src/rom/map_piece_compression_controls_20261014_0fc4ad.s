.setcpu "65816"
.segment "CODE"
.org $C4AD
map_control_0fc4ad:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
