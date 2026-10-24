.setcpu "65816"
.segment "CODE"
.org $2C58
map_control_0f2c58:
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
