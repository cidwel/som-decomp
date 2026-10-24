.setcpu "65816"
.segment "CODE"
.org $0232
map_control_0f0232:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
