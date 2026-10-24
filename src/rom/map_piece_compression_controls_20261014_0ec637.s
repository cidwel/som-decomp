.setcpu "65816"
.segment "CODE"
.org $C637
map_control_0ec637:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
