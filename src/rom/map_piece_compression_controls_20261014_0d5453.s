.setcpu "65816"
.segment "CODE"
.org $5453
map_control_0d5453:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
