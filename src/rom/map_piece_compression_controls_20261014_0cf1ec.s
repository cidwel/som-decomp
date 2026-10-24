.setcpu "65816"
.segment "CODE"
.org $F1EC
map_control_0cf1ec:
    .byte $E6 ; previous-row copy count
