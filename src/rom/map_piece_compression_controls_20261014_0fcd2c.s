.setcpu "65816"
.segment "CODE"
.org $CD2C
map_control_0fcd2c:
    .byte $E1 ; previous-row copy count
