.setcpu "65816"
.segment "CODE"
.org $A20B
map_control_0da20b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
