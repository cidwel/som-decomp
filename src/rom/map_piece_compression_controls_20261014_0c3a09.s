.setcpu "65816"
.segment "CODE"
.org $3A09
map_control_0c3a09:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
