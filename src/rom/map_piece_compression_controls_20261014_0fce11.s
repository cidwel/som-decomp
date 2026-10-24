.setcpu "65816"
.segment "CODE"
.org $CE11
map_control_0fce11:
    .byte $E1 ; previous-row copy count
