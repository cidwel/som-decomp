.setcpu "65816"
.segment "CODE"
.org $5929
map_control_0d5929:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C7 ; same-value copy count/distance
