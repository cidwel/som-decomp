.setcpu "65816"
.segment "CODE"
.org $A220
map_control_0fa220:
    .byte $E5 ; previous-row copy count
