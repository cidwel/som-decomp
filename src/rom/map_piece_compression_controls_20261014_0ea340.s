.setcpu "65816"
.segment "CODE"
.org $A340
map_control_0ea340:
    .byte $E3 ; previous-row copy count
