.setcpu "65816"
.segment "CODE"
.org $1B15
map_control_0f1b15:
    .byte $E0 ; previous-row copy escape
    .byte $B8 ; row-distance/count
