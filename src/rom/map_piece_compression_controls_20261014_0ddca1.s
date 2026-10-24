.setcpu "65816"
.segment "CODE"
.org $DCA1
map_control_0ddca1:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
