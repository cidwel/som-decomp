.setcpu "65816"
.segment "CODE"
.org $A121
map_control_0fa121:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
