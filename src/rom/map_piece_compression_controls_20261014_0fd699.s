.setcpu "65816"
.segment "CODE"
.org $D699
map_control_0fd699:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
