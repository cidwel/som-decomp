.setcpu "65816"
.segment "CODE"
.org $0D72
map_control_0d0d72:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
