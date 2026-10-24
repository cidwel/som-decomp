.setcpu "65816"
.segment "CODE"
.org $A774
map_control_0ea774:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
