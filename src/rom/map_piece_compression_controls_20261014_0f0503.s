.setcpu "65816"
.segment "CODE"
.org $0503
map_control_0f0503:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
