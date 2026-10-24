.setcpu "65816"
.segment "CODE"
.org $24CD
map_control_0d24cd:
    .byte $CB ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
