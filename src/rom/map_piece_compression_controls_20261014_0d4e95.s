.setcpu "65816"
.segment "CODE"
.org $4E95
map_control_0d4e95:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
