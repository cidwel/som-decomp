.setcpu "65816"
.segment "CODE"
.org $0ECA
map_control_0d0eca:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
