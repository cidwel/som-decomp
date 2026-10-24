.setcpu "65816"
.segment "CODE"
.org $EB71
map_control_0eeb71:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
