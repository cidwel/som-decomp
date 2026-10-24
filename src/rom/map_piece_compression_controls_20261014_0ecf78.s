.setcpu "65816"
.segment "CODE"
.org $CF78
map_control_0ecf78:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
