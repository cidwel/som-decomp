.setcpu "65816"
.segment "CODE"
.org $D78A
map_control_0ed78a:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
