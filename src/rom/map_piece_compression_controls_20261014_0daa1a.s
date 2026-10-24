.setcpu "65816"
.segment "CODE"
.org $AA1A
map_control_0daa1a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
