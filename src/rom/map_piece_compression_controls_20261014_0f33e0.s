.setcpu "65816"
.segment "CODE"
.org $33E0
map_control_0f33e0:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
    .byte $E4 ; previous-row copy count
