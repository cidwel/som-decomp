.setcpu "65816"
.segment "CODE"
.org $7CFF
map_control_0f7cff:
    .byte $E1 ; previous-row copy count
