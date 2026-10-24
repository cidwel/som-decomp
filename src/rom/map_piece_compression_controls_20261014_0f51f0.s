.setcpu "65816"
.segment "CODE"
.org $51F0
map_control_0f51f0:
    .byte $E6 ; previous-row copy count
