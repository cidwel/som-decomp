.setcpu "65816"
.segment "CODE"
.org $CD43
map_control_0dcd43:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
