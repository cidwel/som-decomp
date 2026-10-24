.setcpu "65816"
.segment "CODE"
.org $A1EA
map_control_0fa1ea:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
