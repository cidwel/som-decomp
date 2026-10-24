.setcpu "65816"
.segment "CODE"
.org $CD0D
map_control_0fcd0d:
    .byte $E1 ; previous-row copy count
