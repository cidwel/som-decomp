.setcpu "65816"
.segment "CODE"
.org $4019
map_control_0c4019:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
