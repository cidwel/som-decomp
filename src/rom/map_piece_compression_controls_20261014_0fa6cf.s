.setcpu "65816"
.segment "CODE"
.org $A6CF
map_control_0fa6cf:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
