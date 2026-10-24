.setcpu "65816"
.segment "CODE"
.org $74CC
map_control_0d74cc:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
