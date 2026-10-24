.setcpu "65816"
.segment "CODE"
.org $3635
map_control_0c3635:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C3 ; same-value copy count/distance
