.setcpu "65816"
.segment "CODE"
.org $8FB8
map_control_0e8fb8:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
