.setcpu "65816"
.segment "CODE"
.org $A330
map_control_0ea330:
    .byte $E3 ; previous-row copy count
