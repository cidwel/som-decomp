.setcpu "65816"
.segment "CODE"
.org $16CF
map_control_0f16cf:
    .byte $E3 ; previous-row copy count
