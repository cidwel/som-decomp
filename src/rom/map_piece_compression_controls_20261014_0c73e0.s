.setcpu "65816"
.segment "CODE"
.org $73E0
map_control_0c73e0:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
