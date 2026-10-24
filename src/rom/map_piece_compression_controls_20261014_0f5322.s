.setcpu "65816"
.segment "CODE"
.org $5322
map_control_0f5322:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
