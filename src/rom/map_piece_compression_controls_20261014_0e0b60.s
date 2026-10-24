.setcpu "65816"
.segment "CODE"
.org $0B60
map_control_0e0b60:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
