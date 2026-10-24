.setcpu "65816"
.segment "CODE"
.org $75F8
map_control_0c75f8:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
