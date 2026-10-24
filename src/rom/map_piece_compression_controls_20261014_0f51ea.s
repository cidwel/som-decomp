.setcpu "65816"
.segment "CODE"
.org $51EA
map_control_0f51ea:
    .byte $E1 ; previous-row copy count
