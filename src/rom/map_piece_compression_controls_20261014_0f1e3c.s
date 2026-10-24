.setcpu "65816"
.segment "CODE"
.org $1E3C
map_control_0f1e3c:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
