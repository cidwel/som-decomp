.setcpu "65816"
.segment "CODE"
.org $5009
map_control_0d5009:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
