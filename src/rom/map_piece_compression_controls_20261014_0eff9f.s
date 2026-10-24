.setcpu "65816"
.segment "CODE"
.org $FF9F
map_control_0eff9f:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
