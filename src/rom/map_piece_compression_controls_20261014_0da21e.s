.setcpu "65816"
.segment "CODE"
.org $A21E
map_control_0da21e:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
