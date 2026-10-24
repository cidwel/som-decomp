.setcpu "65816"
.segment "CODE"
.org $9268
map_control_0c9268:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
