.setcpu "65816"
.segment "CODE"
.org $23A5
map_control_0c23a5:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
