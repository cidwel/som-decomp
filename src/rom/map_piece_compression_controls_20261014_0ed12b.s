.setcpu "65816"
.segment "CODE"
.org $D12B
map_control_0ed12b:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
