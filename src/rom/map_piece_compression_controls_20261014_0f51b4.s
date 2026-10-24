.setcpu "65816"
.segment "CODE"
.org $51B4
map_control_0f51b4:
    .byte $E5 ; previous-row copy count
