.setcpu "65816"
.segment "CODE"
.org $8E71
map_control_0e8e71:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
