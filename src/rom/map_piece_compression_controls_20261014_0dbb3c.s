.setcpu "65816"
.segment "CODE"
.org $BB3C
map_control_0dbb3c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C3 ; same-value copy count/distance
