.setcpu "65816"
.segment "CODE"
.org $D10C
map_control_0fd10c:
    .byte $E2 ; previous-row copy count
