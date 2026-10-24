.setcpu "65816"
.segment "CODE"
.org $D20D
map_control_0fd20d:
    .byte $E1 ; previous-row copy count
