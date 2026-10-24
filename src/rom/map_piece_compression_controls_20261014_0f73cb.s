.setcpu "65816"
.segment "CODE"
.org $73CB
map_control_0f73cb:
    .byte $E5 ; previous-row copy count
