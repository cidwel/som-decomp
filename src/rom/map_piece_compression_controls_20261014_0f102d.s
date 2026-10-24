.setcpu "65816"
.segment "CODE"
.org $102D
map_control_0f102d:
    .byte $E1 ; previous-row copy count
