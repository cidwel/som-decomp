.setcpu "65816"
.segment "CODE"
.org $A5DA
map_control_0fa5da:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
