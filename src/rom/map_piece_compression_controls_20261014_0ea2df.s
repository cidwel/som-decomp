.setcpu "65816"
.segment "CODE"
.org $A2DF
map_control_0ea2df:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
