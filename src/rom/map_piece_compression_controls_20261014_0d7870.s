.setcpu "65816"
.segment "CODE"
.org $7870
map_control_0d7870:
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
