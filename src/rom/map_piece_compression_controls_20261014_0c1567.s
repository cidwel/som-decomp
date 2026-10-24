.setcpu "65816"
.segment "CODE"
.org $1567
map_control_0c1567:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
