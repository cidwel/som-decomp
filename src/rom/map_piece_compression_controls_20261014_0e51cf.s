.setcpu "65816"
.segment "CODE"
.org $51CF
map_control_0e51cf:
    .byte $E7 ; previous-row copy count
