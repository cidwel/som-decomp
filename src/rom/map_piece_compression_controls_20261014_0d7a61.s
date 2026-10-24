.setcpu "65816"
.segment "CODE"
.org $7A61
map_control_0d7a61:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
