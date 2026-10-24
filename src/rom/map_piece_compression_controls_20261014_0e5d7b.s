.setcpu "65816"
.segment "CODE"
.org $5D7B
map_control_0e5d7b:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
