.setcpu "65816"
.segment "CODE"
.org $A870
map_control_0ea870:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
