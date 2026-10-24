.setcpu "65816"
.segment "CODE"
.org $22CF
map_control_0f22cf:
    .byte $E6 ; previous-row copy count
