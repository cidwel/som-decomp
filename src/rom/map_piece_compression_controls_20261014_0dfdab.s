.setcpu "65816"
.segment "CODE"
.org $FDAB
map_control_0dfdab:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
