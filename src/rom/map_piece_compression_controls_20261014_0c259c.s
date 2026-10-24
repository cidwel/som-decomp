.setcpu "65816"
.segment "CODE"
.org $259C
map_control_0c259c:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
