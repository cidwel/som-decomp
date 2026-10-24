.setcpu "65816"
.segment "CODE"
.org $91AA
map_control_0f91aa:
    .byte $E1 ; previous-row copy count
