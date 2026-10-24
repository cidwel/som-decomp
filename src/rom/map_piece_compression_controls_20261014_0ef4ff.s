.setcpu "65816"
.segment "CODE"
.org $F4FF
map_control_0ef4ff:
    .byte $E2 ; previous-row copy count
