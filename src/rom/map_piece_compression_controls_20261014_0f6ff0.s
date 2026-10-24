.setcpu "65816"
.segment "CODE"
.org $6FF0
map_control_0f6ff0:
    .byte $E1 ; previous-row copy count
