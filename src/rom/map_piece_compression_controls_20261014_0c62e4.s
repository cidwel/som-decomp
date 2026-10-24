.setcpu "65816"
.segment "CODE"
.org $62E4
map_control_0c62e4:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
