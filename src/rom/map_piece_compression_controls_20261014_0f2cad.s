.setcpu "65816"
.segment "CODE"
.org $2CAD
map_control_0f2cad:
    .byte $E3 ; previous-row copy count
