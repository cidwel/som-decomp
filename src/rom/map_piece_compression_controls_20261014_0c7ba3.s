.setcpu "65816"
.segment "CODE"
.org $7BA3
map_control_0c7ba3:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
