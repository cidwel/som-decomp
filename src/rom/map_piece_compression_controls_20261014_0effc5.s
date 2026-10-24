.setcpu "65816"
.segment "CODE"
.org $FFC5
map_control_0effc5:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
