.setcpu "65816"
.segment "CODE"
.org $CF48
map_control_0dcf48:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
