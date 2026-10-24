.setcpu "65816"
.segment "CODE"
.org $F324
map_control_0df324:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
