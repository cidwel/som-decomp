.setcpu "65816"
.segment "CODE"
.org $CBD3
map_control_0fcbd3:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
