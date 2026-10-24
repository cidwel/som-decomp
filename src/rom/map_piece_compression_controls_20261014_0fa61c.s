.setcpu "65816"
.segment "CODE"
.org $A61C
map_control_0fa61c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
