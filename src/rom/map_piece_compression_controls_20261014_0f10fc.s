.setcpu "65816"
.segment "CODE"
.org $10FC
map_control_0f10fc:
    .byte $E1 ; previous-row copy count
