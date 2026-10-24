.setcpu "65816"
.segment "CODE"
.org $A004
map_control_0ea004:
    .byte $E3 ; previous-row copy count
