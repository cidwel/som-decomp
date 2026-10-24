.setcpu "65816"
.segment "CODE"
.org $149B
map_control_0d149b:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
