.setcpu "65816"
.segment "CODE"
.org $A9F2
map_control_0fa9f2:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
