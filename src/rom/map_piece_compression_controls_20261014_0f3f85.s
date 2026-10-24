.setcpu "65816"
.segment "CODE"
.org $3F85
map_control_0f3f85:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
