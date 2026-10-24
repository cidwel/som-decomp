.setcpu "65816"
.segment "CODE"
.org $8070
map_control_0f8070:
    .byte $E7 ; previous-row copy count
