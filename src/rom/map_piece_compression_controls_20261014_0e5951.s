.setcpu "65816"
.segment "CODE"
.org $5951
map_control_0e5951:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
