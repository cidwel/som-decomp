.setcpu "65816"
.segment "CODE"
.org $E131
map_control_0fe131:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
