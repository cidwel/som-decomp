.setcpu "65816"
.segment "CODE"
.org $CD43
map_control_0ecd43:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
