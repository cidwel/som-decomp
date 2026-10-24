.setcpu "65816"
.segment "CODE"
.org $190B
map_control_0e190b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
