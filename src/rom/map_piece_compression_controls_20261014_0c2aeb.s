.setcpu "65816"
.segment "CODE"
.org $2AEB
map_control_0c2aeb:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
