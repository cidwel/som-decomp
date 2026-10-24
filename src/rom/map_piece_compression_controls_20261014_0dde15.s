.setcpu "65816"
.segment "CODE"
.org $DE15
map_control_0dde15:
    .byte $E3 ; previous-row copy count
