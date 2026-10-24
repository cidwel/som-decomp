.setcpu "65816"
.segment "CODE"
.org $D026
map_control_0ed026:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
