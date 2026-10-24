.setcpu "65816"
.segment "CODE"
.org $1AFF
map_control_0d1aff:
    .byte $E6 ; previous-row copy count
