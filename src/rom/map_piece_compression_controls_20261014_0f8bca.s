.setcpu "65816"
.segment "CODE"
.org $8BCA
map_control_0f8bca:
    .byte $E1 ; previous-row copy count
