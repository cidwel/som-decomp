.setcpu "65816"
.segment "CODE"
.org $7012
map_control_0f7012:
    .byte $E1 ; previous-row copy count
