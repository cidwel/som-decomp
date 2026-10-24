.setcpu "65816"
.segment "CODE"
.org $E18B
map_control_0de18b:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
