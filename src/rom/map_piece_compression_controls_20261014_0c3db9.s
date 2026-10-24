.setcpu "65816"
.segment "CODE"
.org $3DB9
map_control_0c3db9:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $D1 ; same-value copy count/distance
