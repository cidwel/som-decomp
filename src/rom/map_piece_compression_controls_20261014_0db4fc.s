.setcpu "65816"
.segment "CODE"
.org $B4FC
map_control_0db4fc:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $CC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
