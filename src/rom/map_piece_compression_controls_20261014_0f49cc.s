.setcpu "65816"
.segment "CODE"
.org $49CC
map_control_0f49cc:
    .byte $E6 ; previous-row copy count
