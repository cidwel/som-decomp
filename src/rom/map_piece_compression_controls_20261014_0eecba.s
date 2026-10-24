.setcpu "65816"
.segment "CODE"
.org $ECBA
map_control_0eecba:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
