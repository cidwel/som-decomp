.setcpu "65816"
.segment "CODE"
.org $05BD
map_control_0f05bd:
    .byte $E2 ; previous-row copy count
