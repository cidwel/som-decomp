.setcpu "65816"
.segment "CODE"
.org $D8DF
map_control_0fd8df:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
