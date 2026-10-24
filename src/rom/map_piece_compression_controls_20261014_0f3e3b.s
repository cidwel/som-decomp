.setcpu "65816"
.segment "CODE"
.org $3E3B
map_control_0f3e3b:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
