.setcpu "65816"
.segment "CODE"
.org $A82B
map_control_0fa82b:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $E5 ; previous-row copy count
