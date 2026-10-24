.setcpu "65816"
.segment "CODE"
.org $860F
map_control_0f860f:
    .byte $E5 ; previous-row copy count
