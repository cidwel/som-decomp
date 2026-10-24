.setcpu "65816"
.segment "CODE"
.org $3A5D
map_control_0c3a5d:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
