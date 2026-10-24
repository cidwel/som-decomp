.setcpu "65816"
.segment "CODE"
.org $8318
map_control_0f8318:
    .byte $E5 ; previous-row copy count
