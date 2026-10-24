.setcpu "65816"
.segment "CODE"
.org $546B
map_control_0e546b:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
