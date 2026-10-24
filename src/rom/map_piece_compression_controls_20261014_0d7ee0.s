.setcpu "65816"
.segment "CODE"
.org $7EE0
map_control_0d7ee0:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
