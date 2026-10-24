.setcpu "65816"
.segment "CODE"
.org $7DDD
map_control_0f7ddd:
    .byte $E5 ; previous-row copy count
