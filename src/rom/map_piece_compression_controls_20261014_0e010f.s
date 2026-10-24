.setcpu "65816"
.segment "CODE"
.org $010F
map_control_0e010f:
    .byte $E1 ; previous-row copy count
