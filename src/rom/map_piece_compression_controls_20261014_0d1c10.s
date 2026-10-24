.setcpu "65816"
.segment "CODE"
.org $1C10
map_control_0d1c10:
    .byte $C3 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
