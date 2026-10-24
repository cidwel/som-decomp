.setcpu "65816"
.segment "CODE"
.org $C131
map_control_0dc131:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
