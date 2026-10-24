.setcpu "65816"
.segment "CODE"
.org $C423
map_control_0dc423:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
