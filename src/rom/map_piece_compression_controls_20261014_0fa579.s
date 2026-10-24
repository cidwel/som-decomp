.setcpu "65816"
.segment "CODE"
.org $A579
map_control_0fa579:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
