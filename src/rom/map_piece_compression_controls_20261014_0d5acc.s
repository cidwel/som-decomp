.setcpu "65816"
.segment "CODE"
.org $5ACC
map_control_0d5acc:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
