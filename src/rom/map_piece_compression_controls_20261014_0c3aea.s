.setcpu "65816"
.segment "CODE"
.org $3AEA
map_control_0c3aea:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
