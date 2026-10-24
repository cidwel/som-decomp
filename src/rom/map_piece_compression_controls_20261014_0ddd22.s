.setcpu "65816"
.segment "CODE"
.org $DD22
map_control_0ddd22:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7D ; row-distance/count
