.setcpu "65816"
.segment "CODE"
.org $F4BF
map_control_0ff4bf:
    .byte $E1 ; previous-row copy count
