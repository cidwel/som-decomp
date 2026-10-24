.setcpu "65816"
.segment "CODE"
.org $AD9F
map_control_0fad9f:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C6 ; same-value copy count/distance
