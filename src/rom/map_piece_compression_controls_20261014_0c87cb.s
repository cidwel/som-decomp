.setcpu "65816"
.segment "CODE"
.org $87CB
map_control_0c87cb:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
