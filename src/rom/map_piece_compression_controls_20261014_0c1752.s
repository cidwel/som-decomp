.setcpu "65816"
.segment "CODE"
.org $1752
map_control_0c1752:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
