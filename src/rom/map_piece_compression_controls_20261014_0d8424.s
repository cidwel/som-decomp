.setcpu "65816"
.segment "CODE"
.org $8424
map_control_0d8424:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
