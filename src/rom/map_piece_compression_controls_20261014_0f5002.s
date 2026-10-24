.setcpu "65816"
.segment "CODE"
.org $5002
map_control_0f5002:
    .byte $E5 ; previous-row copy count
