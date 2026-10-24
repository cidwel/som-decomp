.setcpu "65816"
.segment "CODE"
.org $17CA
map_control_0f17ca:
    .byte $E1 ; previous-row copy count
