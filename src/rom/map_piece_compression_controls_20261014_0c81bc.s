.setcpu "65816"
.segment "CODE"
.org $81BC
map_control_0c81bc:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
