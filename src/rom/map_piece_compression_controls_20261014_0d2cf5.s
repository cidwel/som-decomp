.setcpu "65816"
.segment "CODE"
.org $2CF5
map_control_0d2cf5:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
