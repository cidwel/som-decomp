.setcpu "65816"
.segment "CODE"
.org $A9DD
map_control_0fa9dd:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
