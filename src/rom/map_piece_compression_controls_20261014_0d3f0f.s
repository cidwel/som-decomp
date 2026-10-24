.setcpu "65816"
.segment "CODE"
.org $3F0F
map_control_0d3f0f:
    .byte $E2 ; previous-row copy count
