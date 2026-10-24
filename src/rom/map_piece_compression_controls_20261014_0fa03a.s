.setcpu "65816"
.segment "CODE"
.org $A03A
map_control_0fa03a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
