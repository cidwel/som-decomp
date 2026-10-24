.setcpu "65816"
.segment "CODE"
.org $FB00
map_control_0dfb00:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
