.setcpu "65816"
.segment "CODE"
.org $6CCC
map_control_0e6ccc:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
