.setcpu "65816"
.segment "CODE"
.org $4322
map_control_0f4322:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
