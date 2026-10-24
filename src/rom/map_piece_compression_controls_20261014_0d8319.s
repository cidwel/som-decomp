.setcpu "65816"
.segment "CODE"
.org $8319
map_control_0d8319:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
