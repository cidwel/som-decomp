.setcpu "65816"
.segment "CODE"
.org $25EC
map_control_0f25ec:
    .byte $E1 ; previous-row copy count
