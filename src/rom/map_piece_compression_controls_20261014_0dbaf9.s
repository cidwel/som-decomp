.setcpu "65816"
.segment "CODE"
.org $BAF9
map_control_0dbaf9:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
