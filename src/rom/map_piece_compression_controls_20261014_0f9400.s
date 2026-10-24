.setcpu "65816"
.segment "CODE"
.org $9400
map_control_0f9400:
    .byte $E7 ; previous-row copy count
