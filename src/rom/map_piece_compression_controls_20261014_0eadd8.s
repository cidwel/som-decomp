.setcpu "65816"
.segment "CODE"
.org $ADD8
map_control_0eadd8:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $43 ; distance low bit/count
