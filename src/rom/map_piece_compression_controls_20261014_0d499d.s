.setcpu "65816"
.segment "CODE"
.org $499D
map_control_0d499d:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $CB ; same-value copy count/distance
