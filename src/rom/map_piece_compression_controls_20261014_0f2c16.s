.setcpu "65816"
.segment "CODE"
.org $2C16
map_control_0f2c16:
    .byte $E1 ; previous-row copy count
