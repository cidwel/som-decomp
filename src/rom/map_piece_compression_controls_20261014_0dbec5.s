.setcpu "65816"
.segment "CODE"
.org $BEC5
map_control_0dbec5:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
