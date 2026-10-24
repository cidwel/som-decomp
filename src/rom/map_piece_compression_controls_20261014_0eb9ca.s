.setcpu "65816"
.segment "CODE"
.org $B9CA
map_control_0eb9ca:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
