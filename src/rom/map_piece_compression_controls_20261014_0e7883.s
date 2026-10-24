.setcpu "65816"
.segment "CODE"
.org $7883
map_control_0e7883:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
