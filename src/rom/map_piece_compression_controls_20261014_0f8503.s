.setcpu "65816"
.segment "CODE"
.org $8503
map_control_0f8503:
    .byte $E1 ; previous-row copy count
