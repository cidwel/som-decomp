.setcpu "65816"
.segment "CODE"
.org $58CF
map_control_0f58cf:
    .byte $E1 ; previous-row copy count
