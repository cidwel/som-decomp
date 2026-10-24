.setcpu "65816"
.segment "CODE"
.org $C494
map_control_0dc494:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
