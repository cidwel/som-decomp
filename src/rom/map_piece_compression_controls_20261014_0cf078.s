.setcpu "65816"
.segment "CODE"
.org $F078
map_control_0cf078:
    .byte $E5 ; previous-row copy count
