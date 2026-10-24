.setcpu "65816"
.segment "CODE"
.org $1FAB
map_control_0c1fab:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
