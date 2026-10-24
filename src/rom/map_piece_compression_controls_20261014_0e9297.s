.setcpu "65816"
.segment "CODE"
.org $9297
map_control_0e9297:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
