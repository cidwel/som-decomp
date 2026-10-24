.setcpu "65816"
.segment "CODE"
.org $DF45
map_control_0edf45:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
