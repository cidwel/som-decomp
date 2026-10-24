.setcpu "65816"
.segment "CODE"
.org $8078
map_control_0f8078:
    .byte $E7 ; previous-row copy count
