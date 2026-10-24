.setcpu "65816"
.segment "CODE"
.org $ACD6
map_control_0facd6:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
