.setcpu "65816"
.segment "CODE"
.org $C0BF
map_control_0dc0bf:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
