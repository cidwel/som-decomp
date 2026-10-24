.setcpu "65816"
.segment "CODE"
.org $A8B1
map_control_0fa8b1:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
