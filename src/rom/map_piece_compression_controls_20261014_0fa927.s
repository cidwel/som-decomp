.setcpu "65816"
.segment "CODE"
.org $A927
map_control_0fa927:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
