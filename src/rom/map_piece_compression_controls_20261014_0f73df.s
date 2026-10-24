.setcpu "65816"
.segment "CODE"
.org $73DF
map_control_0f73df:
    .byte $E7 ; previous-row copy count
