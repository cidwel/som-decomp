.setcpu "65816"
.segment "CODE"
.org $2763
map_control_0e2763:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
