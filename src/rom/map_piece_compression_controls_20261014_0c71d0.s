.setcpu "65816"
.segment "CODE"
.org $71D0
map_control_0c71d0:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
