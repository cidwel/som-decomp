.setcpu "65816"
.segment "CODE"
.org $ADB2
map_control_0dadb2:
    .byte $E2 ; previous-row copy count
