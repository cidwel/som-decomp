.setcpu "65816"
.segment "CODE"
.org $E12C
map_control_0fe12c:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
