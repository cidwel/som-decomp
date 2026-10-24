.setcpu "65816"
.segment "CODE"
.org $5D7E
map_control_0f5d7e:
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
