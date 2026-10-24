.setcpu "65816"
.segment "CODE"
.org $75F2
map_control_0d75f2:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
