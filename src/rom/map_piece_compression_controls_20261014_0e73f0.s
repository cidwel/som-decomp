.setcpu "65816"
.segment "CODE"
.org $73F0
map_control_0e73f0:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
