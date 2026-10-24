.setcpu "65816"
.segment "CODE"
.org $6403
map_control_0f6403:
    .byte $E1 ; previous-row copy count
