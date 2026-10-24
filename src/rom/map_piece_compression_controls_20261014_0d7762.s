.setcpu "65816"
.segment "CODE"
.org $7762
map_control_0d7762:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
