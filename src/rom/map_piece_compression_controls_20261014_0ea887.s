.setcpu "65816"
.segment "CODE"
.org $A887
map_control_0ea887:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
