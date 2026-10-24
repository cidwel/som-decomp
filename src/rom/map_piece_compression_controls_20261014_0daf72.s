.setcpu "65816"
.segment "CODE"
.org $AF72
map_control_0daf72:
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
