.setcpu "65816"
.segment "CODE"
.org $ED00
map_control_0fed00:
    .byte $E2 ; previous-row copy count
