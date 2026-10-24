.setcpu "65816"
.segment "CODE"
.org $75ED
map_control_0f75ed:
    .byte $E1 ; previous-row copy count
