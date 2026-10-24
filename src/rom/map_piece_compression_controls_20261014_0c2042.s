.setcpu "65816"
.segment "CODE"
.org $2042
map_control_0c2042:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
