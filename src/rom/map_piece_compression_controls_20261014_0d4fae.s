.setcpu "65816"
.segment "CODE"
.org $4FAE
map_control_0d4fae:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
