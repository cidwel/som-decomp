.setcpu "65816"
.segment "CODE"
.org $A213
map_control_0ea213:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
