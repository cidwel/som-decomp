.setcpu "65816"
.segment "CODE"
.org $750F
map_control_0f750f:
    .byte $E2 ; previous-row copy count
