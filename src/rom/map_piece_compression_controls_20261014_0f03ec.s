.setcpu "65816"
.segment "CODE"
.org $03EC
map_control_0f03ec:
    .byte $E1 ; previous-row copy count
