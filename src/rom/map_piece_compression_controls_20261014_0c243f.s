.setcpu "65816"
.segment "CODE"
.org $243F
map_control_0c243f:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
