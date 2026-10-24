.setcpu "65816"
.segment "CODE"
.org $2712
map_control_0c2712:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
