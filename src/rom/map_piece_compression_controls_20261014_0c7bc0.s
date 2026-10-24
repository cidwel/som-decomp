.setcpu "65816"
.segment "CODE"
.org $7BC0
map_control_0c7bc0:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
