.setcpu "65816"
.segment "CODE"
.org $129B
map_control_0c129b:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
