.setcpu "65816"
.segment "CODE"
.org $2FF2
map_control_0f2ff2:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
