.setcpu "65816"
.segment "CODE"
.org $EED3
map_control_0eeed3:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
