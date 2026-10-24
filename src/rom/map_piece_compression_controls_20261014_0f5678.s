.setcpu "65816"
.segment "CODE"
.org $5678
map_control_0f5678:
    .byte $E6 ; previous-row copy count
