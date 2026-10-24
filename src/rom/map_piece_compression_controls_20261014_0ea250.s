.setcpu "65816"
.segment "CODE"
.org $A250
map_control_0ea250:
    .byte $E7 ; previous-row copy count
