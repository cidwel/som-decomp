.setcpu "65816"
.segment "CODE"
.org $E19E
map_control_0de19e:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
