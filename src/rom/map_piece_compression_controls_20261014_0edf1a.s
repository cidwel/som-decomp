.setcpu "65816"
.segment "CODE"
.org $DF1A
map_control_0edf1a:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
