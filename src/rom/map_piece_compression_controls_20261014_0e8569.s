.setcpu "65816"
.segment "CODE"
.org $8569
map_control_0e8569:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
