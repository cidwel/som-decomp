.setcpu "65816"
.segment "CODE"
.org $A2BF
map_control_0da2bf:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
