.setcpu "65816"
.segment "CODE"
.org $7E94
map_control_0f7e94:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
