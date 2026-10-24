.setcpu "65816"
.segment "CODE"
.org $B9F3
map_control_0eb9f3:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
