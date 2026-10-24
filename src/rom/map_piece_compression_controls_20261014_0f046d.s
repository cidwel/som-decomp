.setcpu "65816"
.segment "CODE"
.org $046D
map_control_0f046d:
    .byte $E1 ; previous-row copy count
