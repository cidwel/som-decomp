.setcpu "65816"
.segment "CODE"
.org $75F0
map_control_0c75f0:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
