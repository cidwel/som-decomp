.setcpu "65816"
.segment "CODE"
.org $BABB
map_control_0fbabb:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
