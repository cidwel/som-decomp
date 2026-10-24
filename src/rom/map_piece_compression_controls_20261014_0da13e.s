.setcpu "65816"
.segment "CODE"
.org $A13E
map_control_0da13e:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
