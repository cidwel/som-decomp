.setcpu "65816"
.segment "CODE"
.org $CF85
map_control_0dcf85:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
