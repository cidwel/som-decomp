.setcpu "65816"
.segment "CODE"
.org $14A9
map_control_0c14a9:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
