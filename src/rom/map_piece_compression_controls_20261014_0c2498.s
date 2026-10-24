.setcpu "65816"
.segment "CODE"
.org $2498
map_control_0c2498:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
