.setcpu "65816"
.segment "CODE"
.org $B7F5
map_control_0fb7f5:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
