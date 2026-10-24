.setcpu "65816"
.segment "CODE"
.org $7EE3
map_control_0f7ee3:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
