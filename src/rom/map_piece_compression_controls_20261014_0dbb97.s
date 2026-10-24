.setcpu "65816"
.segment "CODE"
.org $BB97
map_control_0dbb97:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
