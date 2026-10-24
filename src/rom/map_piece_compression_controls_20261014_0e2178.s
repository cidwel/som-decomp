.setcpu "65816"
.segment "CODE"
.org $2178
map_control_0e2178:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
