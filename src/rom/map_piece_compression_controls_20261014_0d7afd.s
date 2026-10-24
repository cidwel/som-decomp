.setcpu "65816"
.segment "CODE"
.org $7AFD
map_control_0d7afd:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
