.setcpu "65816"
.segment "CODE"
.org $64B9
map_control_0f64b9:
    .byte $E3 ; previous-row copy count
