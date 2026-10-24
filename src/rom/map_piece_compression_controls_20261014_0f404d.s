.setcpu "65816"
.segment "CODE"
.org $404D
map_control_0f404d:
    .byte $E0 ; previous-row copy escape
    .byte $D8 ; row-distance/count
