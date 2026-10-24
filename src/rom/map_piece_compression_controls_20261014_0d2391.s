.setcpu "65816"
.segment "CODE"
.org $2391
map_control_0d2391:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
