.setcpu "65816"
.segment "CODE"
.org $B05A
map_control_0fb05a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
