.setcpu "65816"
.segment "CODE"
.org $1F73
map_control_0f1f73:
    .byte $E5 ; previous-row copy count
