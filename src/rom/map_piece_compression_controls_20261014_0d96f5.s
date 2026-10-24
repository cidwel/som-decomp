.setcpu "65816"
.segment "CODE"
.org $96F5
map_control_0d96f5:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
