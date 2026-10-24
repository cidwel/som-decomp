.setcpu "65816"
.segment "CODE"
.org $A81D
map_control_0fa81d:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
