.setcpu "65816"
.segment "CODE"
.org $0C68
map_control_0e0c68:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
