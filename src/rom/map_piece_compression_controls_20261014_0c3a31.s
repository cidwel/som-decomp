.setcpu "65816"
.segment "CODE"
.org $3A31
map_control_0c3a31:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
