.setcpu "65816"
.segment "CODE"
.org $B5AF
map_control_0fb5af:
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
