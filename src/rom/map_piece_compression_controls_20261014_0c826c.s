.setcpu "65816"
.segment "CODE"
.org $826C
map_control_0c826c:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
