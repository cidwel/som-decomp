.setcpu "65816"
.segment "CODE"
.org $8894
map_control_0e8894:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
