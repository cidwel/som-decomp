.setcpu "65816"
.segment "CODE"
.org $3E24
map_control_0f3e24:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
