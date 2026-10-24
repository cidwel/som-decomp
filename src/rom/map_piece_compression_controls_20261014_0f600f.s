.setcpu "65816"
.segment "CODE"
.org $600F
map_control_0f600f:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
