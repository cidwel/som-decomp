.setcpu "65816"
.segment "CODE"
.org $0D66
map_control_0d0d66:
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
