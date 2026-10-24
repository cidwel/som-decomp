.setcpu "65816"
.segment "CODE"
.org $2BAD
map_control_0d2bad:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
