.setcpu "65816"
.segment "CODE"
.org $C71C
map_control_0fc71c:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
