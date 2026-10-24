.setcpu "65816"
.segment "CODE"
.org $0F4F
map_control_0f0f4f:
    .byte $E1 ; previous-row copy count
