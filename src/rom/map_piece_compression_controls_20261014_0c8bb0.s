.setcpu "65816"
.segment "CODE"
.org $8BB0
map_control_0c8bb0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
