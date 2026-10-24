.setcpu "65816"
.segment "CODE"
.org $A08B
map_control_0ea08b:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
