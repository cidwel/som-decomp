.setcpu "65816"
.segment "CODE"
.org $3BD6
map_control_0f3bd6:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
