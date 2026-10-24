.setcpu "65816"
.segment "CODE"
.org $8C50
map_control_0f8c50:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $CA ; same-value copy count/distance
