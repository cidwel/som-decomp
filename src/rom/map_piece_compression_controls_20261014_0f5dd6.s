.setcpu "65816"
.segment "CODE"
.org $5DD6
map_control_0f5dd6:
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
