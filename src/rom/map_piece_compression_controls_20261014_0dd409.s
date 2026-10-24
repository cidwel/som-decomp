.setcpu "65816"
.segment "CODE"
.org $D409
map_control_0dd409:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
