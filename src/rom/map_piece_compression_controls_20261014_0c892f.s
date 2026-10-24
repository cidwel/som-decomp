.setcpu "65816"
.segment "CODE"
.org $892F
map_control_0c892f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
