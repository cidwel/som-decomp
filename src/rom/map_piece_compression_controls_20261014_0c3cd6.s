.setcpu "65816"
.segment "CODE"
.org $3CD6
map_control_0c3cd6:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
