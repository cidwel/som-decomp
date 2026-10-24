.setcpu "65816"
.segment "CODE"
.org $CAAC
map_control_0ecaac:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C2 ; same-value copy count/distance
