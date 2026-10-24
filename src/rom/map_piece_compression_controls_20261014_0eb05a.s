.setcpu "65816"
.segment "CODE"
.org $B05A
map_control_0eb05a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
