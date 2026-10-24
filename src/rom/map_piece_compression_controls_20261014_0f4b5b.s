.setcpu "65816"
.segment "CODE"
.org $4B5B
map_control_0f4b5b:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
