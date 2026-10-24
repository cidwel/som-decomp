.setcpu "65816"
.segment "CODE"
.org $2CDC
map_control_0f2cdc:
    .byte $E1 ; previous-row copy count
