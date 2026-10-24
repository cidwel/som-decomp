.setcpu "65816"
.segment "CODE"
.org $EB25
map_control_0eeb25:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
