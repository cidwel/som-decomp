.setcpu "65816"
.segment "CODE"
.org $2ACD
map_control_0f2acd:
    .byte $E5 ; previous-row copy count
