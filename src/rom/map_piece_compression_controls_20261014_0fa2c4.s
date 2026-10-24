.setcpu "65816"
.segment "CODE"
.org $A2C4
map_control_0fa2c4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
