.setcpu "65816"
.segment "CODE"
.org $4102
map_control_0c4102:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
