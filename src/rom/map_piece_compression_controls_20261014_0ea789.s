.setcpu "65816"
.segment "CODE"
.org $A789
map_control_0ea789:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
