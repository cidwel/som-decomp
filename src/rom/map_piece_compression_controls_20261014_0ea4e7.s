.setcpu "65816"
.segment "CODE"
.org $A4E7
map_control_0ea4e7:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
