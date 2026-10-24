.setcpu "65816"
.segment "CODE"
.org $FFC1
map_control_0effc1:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
