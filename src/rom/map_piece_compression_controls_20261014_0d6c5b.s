.setcpu "65816"
.segment "CODE"
.org $6C5B
map_control_0d6c5b:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
