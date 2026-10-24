.setcpu "65816"
.segment "CODE"
.org $2AED
map_control_0f2aed:
    .byte $E6 ; previous-row copy count
