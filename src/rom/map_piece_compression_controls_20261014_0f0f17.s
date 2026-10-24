.setcpu "65816"
.segment "CODE"
.org $0F17
map_control_0f0f17:
    .byte $E1 ; previous-row copy count
