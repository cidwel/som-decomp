.setcpu "65816"
.segment "CODE"
.org $9F93
map_control_0d9f93:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
