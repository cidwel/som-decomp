.setcpu "65816"
.segment "CODE"
.org $14B0
map_control_0c14b0:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
