.setcpu "65816"
.segment "CODE"
.org $DDC0
map_control_0dddc0:
    .byte $E1 ; previous-row copy count
