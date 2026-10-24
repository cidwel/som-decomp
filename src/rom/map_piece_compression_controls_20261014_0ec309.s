.setcpu "65816"
.segment "CODE"
.org $C309
map_control_0ec309:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
