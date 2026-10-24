.setcpu "65816"
.segment "CODE"
.org $404A
map_control_0f404a:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
