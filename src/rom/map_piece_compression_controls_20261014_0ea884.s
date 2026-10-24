.setcpu "65816"
.segment "CODE"
.org $A884
map_control_0ea884:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
