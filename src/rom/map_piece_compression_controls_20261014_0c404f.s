.setcpu "65816"
.segment "CODE"
.org $404F
map_control_0c404f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
