.setcpu "65816"
.segment "CODE"
.org $6255
map_control_0d6255:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C3 ; same-value copy count/distance
