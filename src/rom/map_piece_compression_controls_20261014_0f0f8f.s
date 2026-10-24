.setcpu "65816"
.segment "CODE"
.org $0F8F
map_control_0f0f8f:
    .byte $E3 ; previous-row copy count
