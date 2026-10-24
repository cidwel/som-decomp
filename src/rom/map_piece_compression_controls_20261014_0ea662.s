.setcpu "65816"
.segment "CODE"
.org $A662
map_control_0ea662:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
