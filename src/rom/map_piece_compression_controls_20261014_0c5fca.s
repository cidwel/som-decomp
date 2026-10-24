.setcpu "65816"
.segment "CODE"
.org $5FCA
map_control_0c5fca:
    .byte $E1 ; previous-row copy count
    .byte $C9 ; same-value copy count/distance
