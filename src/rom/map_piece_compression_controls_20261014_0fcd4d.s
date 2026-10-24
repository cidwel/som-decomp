.setcpu "65816"
.segment "CODE"
.org $CD4D
map_control_0fcd4d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
