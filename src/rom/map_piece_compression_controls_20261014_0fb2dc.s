.setcpu "65816"
.segment "CODE"
.org $B2DC
map_control_0fb2dc:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
