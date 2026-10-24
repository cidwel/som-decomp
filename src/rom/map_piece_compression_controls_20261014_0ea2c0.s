.setcpu "65816"
.segment "CODE"
.org $A2C0
map_control_0ea2c0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
