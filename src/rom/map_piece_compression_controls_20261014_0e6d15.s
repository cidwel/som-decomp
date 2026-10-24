.setcpu "65816"
.segment "CODE"
.org $6D15
map_control_0e6d15:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
