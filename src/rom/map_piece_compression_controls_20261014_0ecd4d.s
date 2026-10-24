.setcpu "65816"
.segment "CODE"
.org $CD4D
map_control_0ecd4d:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
