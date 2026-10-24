.setcpu "65816"
.segment "CODE"
.org $A401
map_control_0da401:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
