.setcpu "65816"
.segment "CODE"
.org $A510
map_control_0da510:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
