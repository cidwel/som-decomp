.setcpu "65816"
.segment "CODE"
.org $A4CD
map_control_0fa4cd:
    .byte $E1 ; previous-row copy count
