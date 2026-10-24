.setcpu "65816"
.segment "CODE"
.org $1F8B
map_control_0f1f8b:
    .byte $E5 ; previous-row copy count
