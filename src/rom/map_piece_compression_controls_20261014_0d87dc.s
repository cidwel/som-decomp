.setcpu "65816"
.segment "CODE"
.org $87DC
map_control_0d87dc:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
