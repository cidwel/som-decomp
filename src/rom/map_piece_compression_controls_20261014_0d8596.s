.setcpu "65816"
.segment "CODE"
.org $8596
map_control_0d8596:
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
