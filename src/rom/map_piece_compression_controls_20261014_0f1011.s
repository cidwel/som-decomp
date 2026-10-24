.setcpu "65816"
.segment "CODE"
.org $1011
map_control_0f1011:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5A ; row-distance/count
