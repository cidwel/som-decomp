.setcpu "65816"
.segment "CODE"
.org $E39D
map_control_0de39d:
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $66 ; distance low bit/count
