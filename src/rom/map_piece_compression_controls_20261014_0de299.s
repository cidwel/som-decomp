.setcpu "65816"
.segment "CODE"
.org $E299
map_control_0de299:
    .byte $E1 ; previous-row copy count
    .byte $D4 ; same-value copy count/distance
