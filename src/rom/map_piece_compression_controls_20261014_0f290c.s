.setcpu "65816"
.segment "CODE"
.org $290C
map_control_0f290c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
