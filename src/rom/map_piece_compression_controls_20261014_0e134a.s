.setcpu "65816"
.segment "CODE"
.org $134A
map_control_0e134a:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
