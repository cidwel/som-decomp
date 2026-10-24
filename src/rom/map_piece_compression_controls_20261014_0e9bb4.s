.setcpu "65816"
.segment "CODE"
.org $9BB4
map_control_0e9bb4:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
