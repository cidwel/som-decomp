.setcpu "65816"
.segment "CODE"
.org $BB56
map_control_0dbb56:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
