.setcpu "65816"
.segment "CODE"
.org $4EE4
map_control_0f4ee4:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
