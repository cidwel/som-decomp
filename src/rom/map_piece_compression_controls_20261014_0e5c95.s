.setcpu "65816"
.segment "CODE"
.org $5C95
map_control_0e5c95:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
