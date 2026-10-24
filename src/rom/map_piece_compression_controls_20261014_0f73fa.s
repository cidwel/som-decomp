.setcpu "65816"
.segment "CODE"
.org $73FA
map_control_0f73fa:
    .byte $E5 ; previous-row copy count
