.setcpu "65816"
.segment "CODE"
.org $57DB
map_control_0f57db:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
