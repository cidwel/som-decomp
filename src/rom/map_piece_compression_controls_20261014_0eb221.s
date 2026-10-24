.setcpu "65816"
.segment "CODE"
.org $B221
map_control_0eb221:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
