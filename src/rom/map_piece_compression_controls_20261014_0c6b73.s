.setcpu "65816"
.segment "CODE"
.org $6B73
map_control_0c6b73:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
