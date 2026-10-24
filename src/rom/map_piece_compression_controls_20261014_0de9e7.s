.setcpu "65816"
.segment "CODE"
.org $E9E7
map_control_0de9e7:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
