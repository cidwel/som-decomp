.setcpu "65816"
.segment "CODE"
.org $A1C6
map_control_0fa1c6:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
