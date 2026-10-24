.setcpu "65816"
.segment "CODE"
.org $E1E6
map_control_0de1e6:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
