.setcpu "65816"
.segment "CODE"
.org $99BC
map_control_0f99bc:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
