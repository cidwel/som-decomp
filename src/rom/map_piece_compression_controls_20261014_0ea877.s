.setcpu "65816"
.segment "CODE"
.org $A877
map_control_0ea877:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
