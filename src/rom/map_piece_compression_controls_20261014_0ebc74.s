.setcpu "65816"
.segment "CODE"
.org $BC74
map_control_0ebc74:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
