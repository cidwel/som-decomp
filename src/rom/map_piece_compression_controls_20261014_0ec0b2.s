.setcpu "65816"
.segment "CODE"
.org $C0B2
map_control_0ec0b2:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
