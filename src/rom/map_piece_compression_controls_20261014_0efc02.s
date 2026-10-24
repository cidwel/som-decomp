.setcpu "65816"
.segment "CODE"
.org $FC02
map_control_0efc02:
    .byte $E1 ; previous-row copy count
