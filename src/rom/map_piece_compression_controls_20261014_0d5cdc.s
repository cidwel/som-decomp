.setcpu "65816"
.segment "CODE"
.org $5CDC
map_control_0d5cdc:
    .byte $CB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
