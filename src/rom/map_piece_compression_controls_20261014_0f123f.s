.setcpu "65816"
.segment "CODE"
.org $123F
map_control_0f123f:
    .byte $E6 ; previous-row copy count
