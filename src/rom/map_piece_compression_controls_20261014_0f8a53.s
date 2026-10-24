.setcpu "65816"
.segment "CODE"
.org $8A53
map_control_0f8a53:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
    .byte $E1 ; previous-row copy count
