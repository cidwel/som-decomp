.setcpu "65816"
.segment "CODE"
.org $8152
map_control_0f8152:
    .byte $E1 ; previous-row copy count
