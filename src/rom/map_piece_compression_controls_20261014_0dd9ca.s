.setcpu "65816"
.segment "CODE"
.org $D9CA
map_control_0dd9ca:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
