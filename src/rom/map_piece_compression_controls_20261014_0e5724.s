.setcpu "65816"
.segment "CODE"
.org $5724
map_control_0e5724:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
