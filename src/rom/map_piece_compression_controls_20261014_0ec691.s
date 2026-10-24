.setcpu "65816"
.segment "CODE"
.org $C691
map_control_0ec691:
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
