.setcpu "65816"
.segment "CODE"
.org $0F9F
map_control_0f0f9f:
    .byte $E3 ; previous-row copy count
