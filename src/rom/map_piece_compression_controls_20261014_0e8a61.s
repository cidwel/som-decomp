.setcpu "65816"
.segment "CODE"
.org $8A61
map_control_0e8a61:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
