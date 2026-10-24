.setcpu "65816"
.segment "CODE"
.org $A447
map_control_0da447:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
