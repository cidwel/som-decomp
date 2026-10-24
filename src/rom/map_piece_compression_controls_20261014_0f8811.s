.setcpu "65816"
.segment "CODE"
.org $8811
map_control_0f8811:
    .byte $E3 ; previous-row copy count
