.setcpu "65816"
.segment "CODE"
.org $A64D
map_control_0fa64d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
