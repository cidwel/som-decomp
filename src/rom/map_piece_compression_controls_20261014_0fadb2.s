.setcpu "65816"
.segment "CODE"
.org $ADB2
map_control_0fadb2:
    .byte $E5 ; previous-row copy count
