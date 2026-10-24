.setcpu "65816"
.segment "CODE"
.org $9001
map_control_0c9001:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
