.setcpu "65816"
.segment "CODE"
.org $9FDE
map_control_0e9fde:
    .byte $CB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
