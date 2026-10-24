.setcpu "65816"
.segment "CODE"
.org $5AFF
map_control_0f5aff:
    .byte $E1 ; previous-row copy count
