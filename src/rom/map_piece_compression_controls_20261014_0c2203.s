.setcpu "65816"
.segment "CODE"
.org $2203
map_control_0c2203:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
