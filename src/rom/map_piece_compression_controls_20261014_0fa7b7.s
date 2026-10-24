.setcpu "65816"
.segment "CODE"
.org $A7B7
map_control_0fa7b7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
