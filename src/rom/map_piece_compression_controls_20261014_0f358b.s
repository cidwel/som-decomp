.setcpu "65816"
.segment "CODE"
.org $358B
map_control_0f358b:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
