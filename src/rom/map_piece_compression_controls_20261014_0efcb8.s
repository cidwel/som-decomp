.setcpu "65816"
.segment "CODE"
.org $FCB8
map_control_0efcb8:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
