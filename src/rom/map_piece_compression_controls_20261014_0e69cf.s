.setcpu "65816"
.segment "CODE"
.org $69CF
map_control_0e69cf:
    .byte $E2 ; previous-row copy count
