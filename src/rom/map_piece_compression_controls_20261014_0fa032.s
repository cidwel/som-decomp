.setcpu "65816"
.segment "CODE"
.org $A032
map_control_0fa032:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
