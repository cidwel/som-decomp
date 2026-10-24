.setcpu "65816"
.segment "CODE"
.org $74C9
map_control_0c74c9:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
