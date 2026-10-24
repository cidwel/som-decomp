.setcpu "65816"
.segment "CODE"
.org $736D
map_control_0e736d:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
