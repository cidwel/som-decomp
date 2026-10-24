.setcpu "65816"
.segment "CODE"
.org $36D6
map_control_0e36d6:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
