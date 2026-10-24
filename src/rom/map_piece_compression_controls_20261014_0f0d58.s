.setcpu "65816"
.segment "CODE"
.org $0D58
map_control_0f0d58:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
