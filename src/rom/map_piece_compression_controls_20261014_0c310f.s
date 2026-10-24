.setcpu "65816"
.segment "CODE"
.org $310F
map_control_0c310f:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
