.setcpu "65816"
.segment "CODE"
.org $D611
map_control_0fd611:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
