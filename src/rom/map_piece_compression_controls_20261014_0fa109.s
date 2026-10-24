.setcpu "65816"
.segment "CODE"
.org $A109
map_control_0fa109:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
