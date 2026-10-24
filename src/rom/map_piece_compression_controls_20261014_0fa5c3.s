.setcpu "65816"
.segment "CODE"
.org $A5C3
map_control_0fa5c3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
