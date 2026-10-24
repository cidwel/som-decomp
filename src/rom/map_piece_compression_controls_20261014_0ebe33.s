.setcpu "65816"
.segment "CODE"
.org $BE33
map_control_0ebe33:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
