.setcpu "65816"
.segment "CODE"
.org $A7C1
map_control_0fa7c1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
