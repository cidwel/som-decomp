.setcpu "65816"
.segment "CODE"
.org $B4A8
map_control_0fb4a8:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
