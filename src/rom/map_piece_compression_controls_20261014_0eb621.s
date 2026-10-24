.setcpu "65816"
.segment "CODE"
.org $B621
map_control_0eb621:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
