.setcpu "65816"
.segment "CODE"
.org $0DB4
map_control_0c0db4:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
