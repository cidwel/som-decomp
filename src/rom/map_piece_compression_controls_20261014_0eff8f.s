.setcpu "65816"
.segment "CODE"
.org $FF8F
map_control_0eff8f:
    .byte $E3 ; previous-row copy count
