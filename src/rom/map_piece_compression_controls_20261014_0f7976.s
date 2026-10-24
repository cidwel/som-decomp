.setcpu "65816"
.segment "CODE"
.org $7976
map_control_0f7976:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
