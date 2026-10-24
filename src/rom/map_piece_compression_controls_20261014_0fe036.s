.setcpu "65816"
.segment "CODE"
.org $E036
map_control_0fe036:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
