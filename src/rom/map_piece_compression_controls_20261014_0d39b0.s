.setcpu "65816"
.segment "CODE"
.org $39B0
map_control_0d39b0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
