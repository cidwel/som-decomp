.setcpu "65816"
.segment "CODE"
.org $1F5A
map_control_0f1f5a:
    .byte $E5 ; previous-row copy count
