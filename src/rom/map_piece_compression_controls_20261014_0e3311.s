.setcpu "65816"
.segment "CODE"
.org $3311
map_control_0e3311:
    .byte $D1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
