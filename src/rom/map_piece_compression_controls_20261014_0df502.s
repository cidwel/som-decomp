.setcpu "65816"
.segment "CODE"
.org $F502
map_control_0df502:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
