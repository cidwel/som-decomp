.setcpu "65816"
.segment "CODE"
.org $7EB6
map_control_0d7eb6:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
