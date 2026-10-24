.setcpu "65816"
.segment "CODE"
.org $1F93
map_control_0c1f93:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
