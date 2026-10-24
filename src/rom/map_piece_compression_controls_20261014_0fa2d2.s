.setcpu "65816"
.segment "CODE"
.org $A2D2
map_control_0fa2d2:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
