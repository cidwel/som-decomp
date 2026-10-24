.setcpu "65816"
.segment "CODE"
.org $E289
map_control_0de289:
    .byte $D4 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
