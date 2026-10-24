.setcpu "65816"
.segment "CODE"
.org $DD81
map_control_0ddd81:
    .byte $E2 ; previous-row copy count
