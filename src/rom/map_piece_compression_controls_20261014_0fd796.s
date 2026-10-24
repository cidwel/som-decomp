.setcpu "65816"
.segment "CODE"
.org $D796
map_control_0fd796:
    .byte $C1 ; same-value copy count/distance
    .byte $DC ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
