.setcpu "65816"
.segment "CODE"
.org $AD71
map_control_0dad71:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
