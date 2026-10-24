.setcpu "65816"
.segment "CODE"
.org $36F2
map_control_0e36f2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
