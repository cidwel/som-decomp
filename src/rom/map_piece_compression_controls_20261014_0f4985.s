.setcpu "65816"
.segment "CODE"
.org $4985
map_control_0f4985:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
